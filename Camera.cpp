#include "Camera.h"




void Camera::setPosition(vec3 position)
{
	// ���������� ������ - ���������� �� ������ ������� ��������� �� �������� �������
	r = length(position);
	// ���������� ������������ ����:
	// ��� ���� ����� �������� �� ������ ��������� � ����������� (v1)
	// � ��������� ����� ������� �� �������������� ��������� (v2)
	// ��� ����������� ���� ������������ ��������� ������������ ��������������� �������� 
	vec3 v1 = position;
	vec3 v2 = vec3(v1.x, 0, v1.z);
	float cos_y = dot(normalize(v1), normalize(v2));
	angleY = degrees(acos(cos_y));
	// ����������� ������� ���������� �������������� ����:
	// ��� ���� ����� ��������� (v2) � ��������� �������� ����� ��� Ox
	float cos_x = dot(normalize(v2), vec3(1, 0, 0));
	angleX = degrees(acos(cos_x));
	// ������������� ������� (��� ������������� ������ ����������)
	recalculatePosition();
}
Camera::Camera() {
	position = vec3(10.0, 15.0, 17.5);
	vec3 v1 = position;
	vec3 v2 = vec3(v1.x, 0, v1.z);
	float cos_y = dot(normalize(v1), normalize(v2));
	angleY = degrees(acos(cos_y));
	// ����������� ������� ���������� �������������� ����:
	// ��� ���� ����� ��������� (v2) � ��������� �������� ����� ��� Ox
	float cos_x = dot(normalize(v2), vec3(1, 0, 0));
	angleX = degrees(acos(cos_x));
	r = sqrt(pow(position.x, 2)+ pow(position.y, 2)+ pow(position.z, 2));
	recalculatePosition();
}
Camera::Camera(vec3 pos) {
	position = pos;
	vec3 v1 = position;
	vec3 v2 = vec3(v1.x, 0, v1.z);
	float cos_y = dot(normalize(v1), normalize(v2));
	angleY = degrees(acos(cos_y));
	// ����������� ������� ���������� �������������� ����:
	// ��� ���� ����� ��������� (v2) � ��������� �������� ����� ��� Ox
	float cos_x = dot(normalize(v2), vec3(1, 0, 0));
	angleX = degrees(acos(cos_x));
	r = sqrt(pow(position.x, 2) + pow(position.y, 2) + pow(position.z, 2));
	recalculatePosition();
}
Camera::Camera(float x, float y, float z) {
	position = vec3(x,y,z);
	vec3 v1 = position;
	vec3 v2 = vec3(v1.x, 0, v1.z);
	float cos_y = dot(normalize(v1), normalize(v2));
	angleY = degrees(acos(cos_y));
	// ����������� ������� ���������� �������������� ����:
	// ��� ���� ����� ��������� (v2) � ��������� �������� ����� ��� Ox
	float cos_x = dot(normalize(v2), vec3(1, 0, 0));
	angleX = degrees(acos(cos_x));
	r = sqrt(pow(position.x, 2) + pow(position.y, 2) + pow(position.z, 2));
	recalculatePosition();
}

vec3 Camera::getPosition() {
	return position;
}

void Camera::apply() {
	gluLookAt(position.x, position.y, position.z, 0, 0, 0, 0, 1, 0);
}

void Camera::recalculatePosition() {
	position.x = r * sin(radians(90 - angleY)) * cos(radians(angleX));
	position.y = r * cos(radians(90 - angleY));
	position.z = r * sin(radians(90 - angleY)) * sin(radians(angleX));
}
void Camera::rotateLeftRight(float degree) {
	angleX += degree;
	recalculatePosition();
}
void Camera::rotateUpDown(float degree) {
	angleY += degree;
	recalculatePosition();
}

void Camera::zoomInOut(float distance) {
	r -= distance;
	recalculatePosition();
}