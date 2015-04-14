#include "cinder/app/AppNative.h"
#include "cinder/gl/gl.h"
#include "cinder/Color.h"
#include "cinder/Rand.h"

#include <vector>

using namespace ci;
using namespace ci::app;

class VetorApp : public AppNative {

	//　ボールの情報
	struct Ball{
		Color color;
		Vec2f pos;
		float size;
	};

	//　ボールの配列
	std::vector<Ball>balls;

  public:
	void setup();
	void mouseDown( MouseEvent event );	
	void update();
	void draw();


};

void VetorApp::setup()
{
	//　コンストラクタがない場合だとこんな感じ
	Ball ball = { Color::white(), Vec2f::zero() + static_cast<Vec2f>(getWindowSize()) * .5f, 20.0f };
	balls.emplace_back(ball);
}

void VetorApp::mouseDown( MouseEvent event )
{
	Color color = Color(randFloat(0.2f, 1.0f), randFloat(0.2f, 1.0f), randFloat(0.2f, 1.0f));
	Ball ball = { color, event.getPos(), 20.0f };
	balls.emplace_back(ball);


	//
	// push_backとの違い
	//

	//　push_back -> 一時保管して入れ物に入れる(2工程)
	//　emplace_back -> 入れ物に入れる(1工程)
	//　emplace_backの方が工数が1少ないから処理が速い
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

	// ↑のコメントアウトを簡単記述にすると
	for (auto& ball : balls){
		gl::color(ball.color);
		gl::drawStrokedCircle(ball.pos, ball.size);
	}

}

CINDER_APP_NATIVE( VetorApp, RendererGl )
