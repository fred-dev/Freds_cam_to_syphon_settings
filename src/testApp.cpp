#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
    XML.loadFile("mySettings.xml");
    camWidth	= XML.getValue("CAMWIDTH", 1920);
	camHeight	= XML.getValue("CAMHEIGHT", 1080);
	frameRate	= XML.getValue("FRAMERATE", 25);
    grabber.initGrabber(camWidth, camHeight);
    ofSetWindowShape(camWidth, camHeight);
    drawCams=true;
    syphonOut.setName("Camera 1 Output");
 

}

//--------------------------------------------------------------
void testApp::update(){
    ///JUST TO PUSH
    grabber.grabFrame();
    if (grabber.isFrameNew()) {
        syphonOut.publishTexture(&grabber.getTextureReference());
    }

}

//--------------------------------------------------------------
void testApp::draw(){
    if (drawCams==true) {
        grabber.draw(0, 0, camWidth, camHeight);
    }

}
    
//--------------------------------------------------------------
void testApp::keyPressed(int key){
    if (key =='s') {
        grabber.videoSettings();
    }
    if (key=='d') {
        drawCams=!drawCams;
    }


}

//--------------------------------------------------------------
void testApp::keyReleased(int key){

}

//--------------------------------------------------------------
void testApp::mouseMoved(int x, int y){

}

//--------------------------------------------------------------
void testApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void testApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void testApp::dragEvent(ofDragInfo dragInfo){ 

}