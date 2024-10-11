#include "simulation.h"

float getFPS() {
	long long oldTicks = ticks.LowPart;
	QueryPerformanceCounter(&ticks);
	long long newTicks = ticks.LowPart - oldTicks;
	QueryPerformanceFrequency(&ticksPerSecond);
	float rez = ticksPerSecond.QuadPart / newTicks;
	return rez;
}

void simulation()
{
	int fps = getFPS();
	glutSetWindowTitle(to_string(fps).c_str());
	// устанавливаем признак того, что окно нуждается в перерисовке
	glutPostRedisplay();
	keyboard();
	// эта же функция будет вызвана еще раз через 20 мс
	glutPostRedisplay();

};
void keyboard()
{
	int keyLeft = GetAsyncKeyState(VK_LEFT);
	int keyRight = GetAsyncKeyState(VK_RIGHT);
	int keyUp = GetAsyncKeyState(VK_UP);
	int keyDown = GetAsyncKeyState(VK_DOWN);
	int keyPlus = GetAsyncKeyState(VK_ADD);
	int keySub = GetAsyncKeyState(VK_SUBTRACT);
	// для провекри класса камеры вызываем методы передвижения
	if (keyUp & 0x01)
	{
		camera.rotateUpDown(5.0);
		return;
	}
	if (keyDown & 0x01)
	{
		camera.rotateUpDown(-5.0);
		return;
	}
	if (keyRight & 0x01)
	{
		camera.rotateLeftRight(5.0);
		return;
	}
	if (keyLeft & 0x01)
	{
		camera.rotateLeftRight(-5.0);
		return;
	}
	if (keyPlus & 0x01)
	{
		camera.zoomInOut(0.2);
		return;
	}
	if (keySub & 0x01)
	{
		camera.zoomInOut(-0.2);
		return;
	}

};