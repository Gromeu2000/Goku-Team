#include <stdlib.h>

#include "p2Defs.h"
#include "p2Log.h"
#include "ModuleApp.h"

// This is needed here because SDL redefines main function
// do not add any other libraries here, instead put them in their modules
#include "SDL/include/SDL.h"
#pragma comment( lib, "SDL/libx86/SDL2.lib" )
#pragma comment( lib, "SDL/libx86/SDL2main.lib" )

enum MainState
{
	CREATE = 1,
	AWAKE,
	START,
	LOOP,
	CLEAN,
	FAIL,
	EXIT
};

ModuleApp* App = NULL;

int main(int argc, char* args[])
{
	LOG("Engine starting ...");

	MainState state = CREATE;
	int result = EXIT_FAILURE;

	while (state != EXIT)
	{
		switch (state)
		{

			// Allocate the engine --------------------------------------------
		case CREATE:
			//LOG("CREATION PHASE ===============================");

			App = new ModuleApp(argc, args);

			if (App != NULL)
				state = AWAKE;
			else
				state = FAIL;

			break;

			// Awake all modules -----------------------------------------------
		case AWAKE:
			//LOG("AWAKE PHASE ===============================");
			if (App->Awake() == true)
				state = START;
			else
			{
			//	LOG("ERROR: Awake failed");
				state = FAIL;
			}

			break;

			// Call all modules before first frame  ----------------------------
		case START:
			//LOG("START PHASE ===============================");
			if (App->Start() == true)
			{
				state = LOOP;
			//	LOG("UPDATE PHASE ===============================");
			}
			else
			{
				state = FAIL;
			//	LOG("ERROR: Start failed");
			}
			break;

			// Loop all modules until we are asked to leave ---------------------
		case LOOP:
			if (App->Update() == false)
				state = CLEAN;
			break;

			// Cleanup allocated memory -----------------------------------------
		case CLEAN:
			//LOG("CLEANUP PHASE ===============================");
			if (App->CleanUp() == true)
			{
				RELEASE(App);
				result = EXIT_SUCCESS;
				state = EXIT;
			}
			else
				state = FAIL;

			break;

			// Exit with errors and shame ---------------------------------------
		case FAIL:
			LOG("Exiting with errors :(");
			result = EXIT_FAILURE;
			state = EXIT;
			break;
		}
	}

	LOG("... Bye! :)\n");

	// Dump memory leaks
	return result;
}

//int integratorX(int x_, int v_, int t_, int a_ = 0)
//{
//	return (x_ + v_ * t_);
//}
//int integratorV(int x_, int v_, int t_, int a_ = 0)
//{
//	return (v_ + a_ * t_);
//}
//int main()
//{
//	
//	int Xi = 0;
//	int V = 3;
//	int Tf = 5;
//	int T = 1;
//	std::cout << "xi:" << Xi << "  vi:" << V << "  a:0" << std::endl;
//
//	for (T; T <= Tf; T++)
//	{
//		std::cout <<"T:"<< T << "  x:" << integratorX(Xi, V, T) << "  v:" << integratorV(Xi, V, T) << "  a:0" << std::endl;
//		
//	}
//
//	system("pause");
//	return 0;
//}
