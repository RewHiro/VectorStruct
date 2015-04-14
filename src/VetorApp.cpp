#include "cinder/app/AppNative.h"
#include "cinder/gl/gl.h"
#include "cinder/Color.h"
#include "cinder/Rand.h"

#include <vector>

using namespace ci;
using namespace ci::app;

class VetorApp : public AppNative {

	//�@�{�[���̏��
	struct Ball{
		Color color;
		Vec2f pos;
		float size;
	};

	//�@�{�[���̔z��
	std::vector<Ball>balls;

  public:
	void setup();
	void mouseDown( MouseEvent event );	
	void update();
	void draw();


};

void VetorApp::setup()
{
	//�@�R���X�g���N�^���Ȃ��ꍇ���Ƃ���Ȋ���
	Ball ball = { Color::white(), Vec2f::zero() + static_cast<Vec2f>(getWindowSize()) * .5f, 20.0f };
	balls.emplace_back(ball);
}

void VetorApp::mouseDown( MouseEvent event )
{
	Color color = Color(randFloat(0.2f, 1.0f), randFloat(0.2f, 1.0f), randFloat(0.2f, 1.0f));
	Ball ball = { color, event.getPos(), 20.0f };
	balls.emplace_back(ball);


	//
	// push_back�Ƃ̈Ⴂ
	//

	//�@push_back -> �ꎞ�ۊǂ��ē��ꕨ�ɓ����(2�H��)
	//�@emplace_back -> ���ꕨ�ɓ����(1�H��)
	//�@emplace_back�̕����H����1���Ȃ����珈��������
}

void VetorApp::update()
{
}

void VetorApp::draw()
{
	// clear out the window with black
	gl::clear( Color( 0, 0, 0 ) ); 



	//for (std::vector<Ball>::iterator& ball = balls.begin(); ball != balls.end(); ball++){
	//	gl::color(ball->color);
	//	gl::drawStrokedCircle(ball->pos, ball->size);
	//}

	// ���̃R�����g�A�E�g���ȒP�L�q�ɂ����
	for (auto& ball : balls){
		gl::color(ball.color);
		gl::drawStrokedCircle(ball.pos, ball.size);
	}

}

CINDER_APP_NATIVE( VetorApp, RendererGl )
