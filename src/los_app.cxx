#include "cinder/app/App.h"
#include "cinder/app/RendererGl.h"
#include "cinder/gl/gl.h"

class LordOfCinderApp: public ci::app::App {
  public:
    void draw() override;

};

void prepareSettings(LordOfCinderApp::Settings* settings) {
    settings->setMultiTouchEnabled(false);
}

void LordOfCinderApp::draw()
{
	ci::gl::clear( ci::Color::gray(0.2f) );

    ci::CameraPersp cam;
    cam.lookAt(ci::vec3(5, 5, 5), ci::vec3(0));
    ci::gl::setMatrices(cam);

    ci::gl::color(0.98f, 0.22f, 0.10f);
	ci::gl::drawCube( ci::vec3( 0 ), ci::vec3( 2, 2, 2 ) );
}

CINDER_APP(LordOfCinderApp, ci::app::RendererGl((ci::app::RendererGl::Options().msaa(16))), prepareSettings)