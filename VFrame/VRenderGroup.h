#pragma once
#include "VGroup.h"
#include "VSprite.h"
#include "VPostEffect.h"
#include <SFML\Graphics\Sprite.hpp>
#include <SFML\Graphics\RenderTexture.hpp>

class VRenderGroup : public VGroup
{
protected:
	sf::RenderTexture renderTex;
	sf::RenderTexture postProcessTex;
	void updateTransform();
	void updateTexture(const sf::Texture& texture);

public:
	typedef VGroup VSUPERCLASS;

	VSprite* Sprite = NULL;

	VPostEffectBase* PostEffect = NULL;
	bool RenderViewTransform = true;
	bool RenderOutside = false;

	VRenderGroup(float x, float y, unsigned int width, unsigned int height, unsigned int maxSize = 0);
	VRenderGroup(sf::Vector2f position, sf::Vector2u size, unsigned int maxSize = 0);
	virtual ~VRenderGroup()
	{
		Destroy();
	}

	virtual void Resize(int width, int height);

	virtual const sf::Texture& GetTexture();

	virtual void Kill() override;
	virtual void Revive() override;
	virtual void Destroy() override;
	virtual void Update(float dt) override;
	virtual void Draw(sf::RenderTarget& RenderTarget) override;
};