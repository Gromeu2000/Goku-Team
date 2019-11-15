#ifndef __Physics_H__
#define __Physics_H__

#include "Application.h"
#include "p2String.h"
#include "p2Point"




struct Object
{
	p2SString	name;
	iPoint		pos;
	iPoint		speed;
	iPoint		force;
	float		mass;


};


class ModulePhysics : public Module
{
public:
	ModulePhysics(Application*app, bool start_enabled = true);
	ModulePhysics();

	bool Start();
	update_status Update();
	bool CleanUp();
};








int integratorX(int x_, int v_, int t_, int a_ = 0)
{
	return (x_ + v_ * t_);
}
int integratorV(int x_, int v_, int t_, int a_ = 0)
{
	return (v_ + a_ * t_);
}
int main()
{

	int Xi = 0;
	int V = 3;
	int Tf = 5;
	int T = 1;
	std::cout << "xi:" << Xi << "  vi:" << V << "  a:0" << std::endl;

	for (T; T <= Tf; T++)
	{
		std::cout << "T:" << T << "  x:" << integratorX(Xi, V, T) << "  v:" << integratorV(Xi, V, T) << "  a:0" << std::endl;

	}

	system("pause");
	return 0;
}




#endif // __Physics_H__