#include "cinder/app/App.h"
#include "cinder/app/RendererGl.h"
#include "cinder/gl/gl.h"
#include "cinder/CameraUi.h"

class LordOfCinderApp: public ci::app::App {
  public:
    void setup() override;
    void mouseDown(ci::app::MouseEvent event) override;
    void mouseDrag(ci::app::MouseEvent event) override;
    void resize() override;
    void draw() override;

  private:
    ci::CameraPersp camera;
    ci::CameraUi camera_ui;
    ci::gl::BatchRef cube_batch;
    ci::Color cube_color;

    static constexpr uint64_t los_color_red = 0xe50000;
};

void prepareSettings(LordOfCinderApp::Settings* settings) {
    settings->setMultiTouchEnabled(false);
}

void LordOfCinderApp::setup() {
    auto lambert = ci::gl::ShaderDef().lambert().color();
    ci::gl::GlslProgRef shader = ci::gl::getStockShader(lambert);
    this->cube_batch = ci::gl::Batch::create(ci::geom::Cube(), shader);
    this->cube_color = ci::Color::hex(this->los_color_red);

    this->camera.lookAt(ci::vec3(5,5,5), ci::vec3(0));
    this->camera_ui.setCamera(&this->camera);
}

void LordOfCinderApp::mouseDown(ci::app::MouseEvent event) {
    this->camera_ui.mouseDown(event);
}

void LordOfCinderApp::mouseDrag(ci::app::MouseEvent event) {
    this->camera_ui.mouseDrag(event);
}

void LordOfCinderApp::resize() {
    this->camera.setAspectRatio(ci::app::getWindowAspectRatio());
}

void LordOfCinderApp::draw()
{
	ci::gl::clear(ci::Color::gray(0.2f));
    ci::gl::enableDepthRead();
    ci::gl::enableDepthWrite();

    ci::gl::setMatrices(this->camera);

    ci::gl::color(this->cube_color);
	this->cube_batch->draw();
}

CINDER_APP(LordOfCinderApp, ci::app::RendererGl((ci::app::RendererGl::Options().msaa(16))), prepareSettings)