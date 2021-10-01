#include <irrlicht.h>
#include "KeyEventReceiver.h"

using namespace irr;
using namespace core;
using namespace scene;
using namespace video;
using namespace io;
using namespace gui;

#ifdef _IRR_WINDOWS_
#pragma comment(lib, "Irrlicht.lib")
#pragma comment(linker, "/subsystem:windows /ENTRY:mainCRTStartup")
#endif


#include <iostream>

int main()
{
	KeyEventReceiver keyReceiver;
	IrrlichtDevice* device =
		createDevice(video::EDT_DIRECT3D9, dimension2d<u32>(640, 480), 16,
			false, false, false, &keyReceiver);
	if (!device)
		return 1;
	device->setWindowCaption(L"Hello World! - Irrlicht Engine Demo");
	IVideoDriver* driver = device->getVideoDriver();
	ISceneManager* smgr = device->getSceneManager();


	// 태양을 구현한 부분
	scene::ISceneNode* sunNode = smgr->addSphereSceneNode();
	if (sunNode)
	{
		sunNode->setScale(core::vector3df(10.0f, 10.0f, 10.0f));
		sunNode->setPosition(core::vector3df(0, 0, 30));
		sunNode->setMaterialTexture(0, driver->getTexture("suntexture.jpg"));
		sunNode->setMaterialFlag(video::EMF_LIGHTING, false);
	}


	// 수성을 구현한 부분
	scene::ISceneNode* mercuryNode = smgr->addSphereSceneNode();
	if (mercuryNode)
	{
		mercuryNode->setScale(core::vector3df(0.1f, 0.1f, 0.1f));
		sunNode->addChild(mercuryNode);
		mercuryNode->setMaterialTexture(0, driver->getTexture("mercurytexture.jpg"));
		mercuryNode->setMaterialFlag(video::EMF_LIGHTING, false);

		scene::ISceneNodeAnimator* anim = smgr->createFlyCircleAnimator(core::vector3df(0, 0, 0), 8.0f,0.001f,core::vector3df(1.0f,0.1f,0));
		if (anim)
		{
			mercuryNode->addAnimator(anim);
			anim->drop();
		}
	}

	// 금성을 구현한 부분
	scene::ISceneNode* venusNode = smgr->addSphereSceneNode();
	if (venusNode)
	{
		venusNode->setScale(core::vector3df(0.2f, 0.2f, 0.2f));
		sunNode->addChild(venusNode);
		venusNode->setMaterialTexture(0, driver->getTexture("venustexture.jpg"));
		venusNode->setMaterialFlag(video::EMF_LIGHTING, false);

		scene::ISceneNodeAnimator* anim = smgr->createFlyCircleAnimator(core::vector3df(0, 0, 0), 10.0f,0.0008f,core::vector3df(2.0f,0.5f,0));

		if (anim)
		{
			venusNode->addAnimator(anim);
			anim->drop();
		}
	}
	
	// 지구를 구현한 부분
	scene::ISceneNode* earthNode = smgr->addSphereSceneNode();
	if (earthNode)
	{
		earthNode->setScale(core::vector3df(0.3f, 0.3f, 0.3f));
		sunNode->addChild(earthNode);
		earthNode->setMaterialTexture(0, driver->getTexture("earthtexture.jpg"));
		earthNode->setMaterialFlag(video::EMF_LIGHTING, false);

		scene::ISceneNodeAnimator* anim = smgr->createFlyCircleAnimator(core::vector3df(0, 0, 0), 13.0f,0.0005f,core::vector3df(3.0f,1.0f,0));

		if (anim)
		{
			earthNode->addAnimator(anim);
			anim->drop();
		}
	}

	// 달을 구현한 부분
	scene::ISceneNode* moonNode = smgr->addSphereSceneNode();
	if (moonNode)

	{
		moonNode->setScale(core::vector3df(0.2f, 0.2f,0.2f));
		earthNode->addChild(moonNode);
		moonNode->setMaterialTexture(0, driver->getTexture("moontexture.jpg"));
		moonNode->setMaterialFlag(video::EMF_LIGHTING, false);

		scene::ISceneNodeAnimator* anim = smgr->createFlyCircleAnimator(core::vector3df(0, 0, 0), 10.0f, 0.005f, core::vector3df(0.5f, 0.5f, 0));

		if (anim)
		{
			moonNode->addAnimator(anim);
			anim->drop();
		}
	}

	// 화성을 구현한 부분
	scene::ISceneNode* marsNode = smgr->addSphereSceneNode();
	if (marsNode)
	{
		marsNode->setScale(core::vector3df(0.3f, 0.3f, 0.3f));
		sunNode->addChild(marsNode);
		marsNode->setMaterialTexture(0, driver->getTexture("marstexture.jpg"));
		marsNode->setMaterialFlag(video::EMF_LIGHTING, false);

		scene::ISceneNodeAnimator* anim = smgr->createFlyCircleAnimator(core::vector3df(0, 0, 0), 16.0f,0.0004f,core::vector3df(4.5f,2.0f,0));

		if (anim)
		{
			marsNode->addAnimator(anim);
			anim->drop();
		}
	}

	// 목성을 구현한 부분
	scene::ISceneNode* jupiterNode = smgr->addSphereSceneNode();
	if (jupiterNode)
	{
		jupiterNode->setScale(core::vector3df(0.7f, 0.7f, 0.7f));
		sunNode->addChild(jupiterNode);
		jupiterNode->setMaterialTexture(0, driver->getTexture("jupitertexture.jpg"));
		jupiterNode->setMaterialFlag(video::EMF_LIGHTING, false);

		scene::ISceneNodeAnimator* anim = smgr->createFlyCircleAnimator(core::vector3df(0, 0, 0), 20.0f, 0.0002f, core::vector3df(2.5f, 1.5f, 0));

		if (anim)
		{
			jupiterNode->addAnimator(anim);
			anim->drop();
		}
	}
	// 토성을 구현한 부분

	scene::ISceneNode* saturnNode = smgr->addSphereSceneNode();
	if (saturnNode)
	{
		saturnNode->setScale(core::vector3df(0.5f, 0.5f, 0.5f));
		sunNode->addChild(saturnNode);
		saturnNode->setMaterialTexture(0, driver->getTexture("saturntexture.jpg"));
		saturnNode->setMaterialFlag(video::EMF_LIGHTING, false);

		scene::ISceneNodeAnimator* anim = smgr->createFlyCircleAnimator(core::vector3df(0, 0, 0), 35.0f, 0.00025f, core::vector3df(1.5f, 1.5f, 0));

		if (anim)
		{
			saturnNode->addAnimator(anim);
			anim->drop();
		}
	}

	// 토성의 고리를 구현한 부분
	scene::ISceneNode* ringOfSaturnNode = smgr->addSphereSceneNode();
	if (ringOfSaturnNode)
	{
		ringOfSaturnNode->setScale(core::vector3df(2.5f,0.15f, 2.5f));
		saturnNode->addChild(ringOfSaturnNode);
		ringOfSaturnNode->setMaterialTexture(0, driver->getTexture("ringofsaturntexture.jpg"));
		ringOfSaturnNode->setMaterialFlag(video::EMF_LIGHTING, false);
	}
	
	// 천왕성을 구현한 부분
	scene::ISceneNode* uranusNode = smgr->addSphereSceneNode();
	if (uranusNode)
	{
		uranusNode->setScale(core::vector3df(0.5f, 0.5f, 0.5f));
		sunNode->addChild(uranusNode);
		uranusNode->setMaterialTexture(0, driver->getTexture("uranustexture.jpg"));
		uranusNode->setMaterialFlag(video::EMF_LIGHTING, false);

		scene::ISceneNodeAnimator* anim = smgr->createFlyCircleAnimator(core::vector3df(0, 0, 0), 45.0f,0.00015f,core::vector3df(0.5f,0.1f,0));

		if (anim)
		{
			uranusNode->addAnimator(anim);
			anim->drop();
		}
	}


	IGUIEnvironment* guienv = device->getGUIEnvironment();
	guienv->addStaticText(L"Hello World! This is the Irrlicht Software renderer!",
		rect<s32>(10, 10, 260, 22), true);


	smgr->addCameraSceneNodeFPS();
	device->getCursorControl()->setVisible(false);

	const f32 MOVEMENT_SPEED = 5.0f;

	u32 then = device->getTimer()->getTime();


	// 태양계 행성들의 회전속도 설정
	// 기본값으로 1.0, 0.0, 0.0 을 넣고 아래 업데이트 부분에서 속도 설정.
	core::vector3df sunRotationSpeed = {1.0f,0.0f,0.0f};
	core::vector3df mercuryRotationSpeed = { 1.0f, 0.0f, 0.0f };
	core::vector3df venusRotationSpeed = { 1.0f, 0.0f, 0.0f };
	core::vector3df earthRotationSpeed = { 1.0f, 0.0f, 0.0f };
	core::vector3df marsRotationSpeed = { 1.0f, 0.0f, 0.0f };
	core::vector3df jupiterRotationSpeed = { 1.0f, 0.0f, 0.0f };
	core::vector3df saturnRotationSpeed = { 1.0f,0.0f,0.0f };
	core::vector3df uranusRotationSpeed = { 1.0f,0.0f,0.0f };

	while (device->run())
	{

		// 프레임 체크
		const u32 now = device->getTimer()->getTime();
		const f32 frameDeltaTime = (f32)(now - then) / 1000.0f;
		then = now;

		sunNode->setRotation(sunRotationSpeed);
		mercuryNode->setRotation(mercuryRotationSpeed);
		venusNode->setRotation(venusRotationSpeed);
		earthNode->setRotation(earthRotationSpeed);
		marsNode->setRotation(marsRotationSpeed);
		jupiterNode->setRotation(jupiterRotationSpeed);
		saturnNode->setRotation(saturnRotationSpeed);
		uranusNode->setRotation(uranusRotationSpeed);



		sunRotationSpeed += 1.5f *frameDeltaTime;
		mercuryRotationSpeed += 2.5f * frameDeltaTime;
		venusRotationSpeed += 4.5f * frameDeltaTime;
		earthRotationSpeed += 8.5f * frameDeltaTime;
		marsRotationSpeed += 9.5f * frameDeltaTime;
		jupiterRotationSpeed += 7.5f * frameDeltaTime;
		saturnRotationSpeed += 1.5f * frameDeltaTime;
		uranusRotationSpeed += 6.5f *frameDeltaTime;


		core::vector3df nodePosition = sunNode->getPosition();

		if (keyReceiver.IsKeyDown(irr::KEY_KEY_W))
		{
			nodePosition.Y -= MOVEMENT_SPEED * frameDeltaTime;
		}
		else if (keyReceiver.IsKeyDown(irr::KEY_KEY_S))
		{
			nodePosition.Y += MOVEMENT_SPEED * frameDeltaTime;
		}
		if (keyReceiver.IsKeyDown(irr::KEY_KEY_A))
		{
			nodePosition.X += MOVEMENT_SPEED * frameDeltaTime;
		}
		else if (keyReceiver.IsKeyDown(irr::KEY_KEY_D))
		{
			nodePosition.X -= MOVEMENT_SPEED * frameDeltaTime;
		}

		sunNode->setPosition(nodePosition);

		if (keyReceiver.IsKeyDown(irr::KEY_ESCAPE))
		{
			break;
		}


		driver->beginScene(true, true, SColor(255, 100, 101, 140));
		smgr->drawAll();
		guienv->drawAll();
		driver->endScene();
	}
	device->drop();
	return 0;
}