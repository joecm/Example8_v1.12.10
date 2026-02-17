#include "BaseApp.hpp"
#include <iostream>

class Example : public BaseApp {
    public:
        Example(Ogre::String name="OgreBook_Example") : BaseApp(name) {}
    protected:
        void createScene() override
        {
            mScnMgr->setAmbientLight(Ogre::ColourValue(1.0F, 1.0F, 1.0F));
            
            Ogre::Entity* ent = mScnMgr->createEntity("MyEntity", "Sinbad.mesh");
            Ogre::SceneNode* node = mScnMgr->createSceneNode("Node1");
            mScnMgr->getRootSceneNode()->addChild(node);
            node->attachObject(ent);
            
            Ogre::Entity* ent2 = mScnMgr->createEntity("MyEntity2", "Sinbad.mesh");
            Ogre::SceneNode* node2 = mScnMgr->getRootSceneNode()->createChildSceneNode("Node2");
            node2->setPosition(10.0f, 0.0f, 0.0f);
            node2->yaw(Ogre::Degree(90), Ogre::Node::TS_LOCAL);
            node2->roll(Ogre::Degree(90), Ogre::Node::TS_LOCAL);
            node2->attachObject(ent2);
            
            Ogre::Entity* ent3 = mScnMgr->createEntity("MyEntity3", "Sinbad.mesh");
            Ogre::SceneNode* node3 = node->createChildSceneNode("MyNode3");
            node3->setPosition(20.0f, 0.0f, 0.0f);
            node3->yaw(Ogre::Degree(90), Ogre::Node::TS_WORLD);
            node3->roll(Ogre::Degree(90), Ogre::Node::TS_WORLD);
            node3->attachObject(ent3);
            
        }
};

int main(int argc, char** argv)
{
    try {
        Example app ("Ejemplo 8");
        app.initApp();
        app.getRoot()->startRendering();
        app.closeApp();
    } catch (const std::exception& e) {
        std::cerr << "Error occurred during execution: " << e.what() << std::endl;
        return EXIT_FAILURE;
    }
    return EXIT_SUCCESS;
}
