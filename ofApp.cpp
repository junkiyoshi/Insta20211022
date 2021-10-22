#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup() {

	ofSetFrameRate(30);
	ofSetWindowTitle("openFrameworks");

	ofBackground(239);
	ofSetColor(39);
	ofEnableBlendMode(ofBlendMode::OF_BLENDMODE_MULTIPLY);
}

//--------------------------------------------------------------
void ofApp::update() {

	this->mesh.clear();

	int size = 3;
	for (int x = 100; x < ofGetWidth() - 100; x += size) {

		for (int y = 100; y < ofGetHeight() - 100; y += size) {

			float deg = ofMap(ofNoise(x * 0.0035, y * 0.0035, ofGetFrameNum() * 0.03), 0, 1, -360, 360);
			glm::vec3 location = glm::vec3(x + size * 3 * cos(deg * DEG_TO_RAD), y + size * 3 * sin(deg * DEG_TO_RAD), 0);
			this->mesh.addVertex(location);
		}
	}
}

//--------------------------------------------------------------
void ofApp::draw() {

	this->mesh.drawVertices();
}


//--------------------------------------------------------------
int main() {
	ofSetupOpenGL(720, 720, OF_WINDOW);
	ofRunApp(new ofApp());
}