# include "include/Kamino.h"
//# include "include/HH16Sphere.h"
# include <fstream>

int main(int argc, char** argv)
{
	if (argc == 2)
	{
		std::string configFile = argv[1];
		std::fstream fin;
		fin.open(configFile, std::ios::in);
		fReal radius; size_t nTheta; fReal particleDensity;
		float dt; float DT; int frames;
		float A; int B; int C; int D; int E;
		std::string gridPath; std::string particlePath;
		std::string densityImage; std::string solidImage; std::string colorImage;

		//default value: 5.0
		fin >> radius;
		//default value: 256
		fin >> nTheta;
		//default value: 10.0
		fin >> particleDensity;
		//default value: 0.005
		fin >> dt;
		//default value: 1.0/24.0
		fin >> DT;
		//default value: 10
		fin >> frames;
		//default value: 0.0
		fin >> A;
		//default value: 1
		fin >> B;
		//default value: 1
		fin >> C;
		//default value: 1
		fin >> D;
		//default value: 1
		fin >> E;
		//default value: output/frame
		fin >> gridPath;
		//default value: particles/frame
		fin >> particlePath;
		//default value: ""
		fin >> densityImage;
		if (densityImage == "null")
		{
			densityImage = "";
		}
		//default value: ""
		fin >> solidImage;
		if (solidImage == "null")
		{
			solidImage == "";
		}
		//default value: ""
		fin >> colorImage;
		if (colorImage == "null")
		{
			colorImage = "";
		}

		Kamino KaminoInstance(radius, nTheta, particleDensity, dt, DT, frames,
			A, B, C, D, E,
			gridPath, particlePath, densityImage, solidImage, colorImage);

		//Kamino KaminoInstance;
		KaminoInstance.run();
		return 0;
	}
	else
	{
		std::cout << "Please provide the path to configKamino.txt as an argument." << std::endl;
		std::cout << "Usage example: ./kamino.exe ./configKamino.txt" << std::endl;
		std::cout << "Configuration file was missing, exiting." << std::endl;
		return -1;
	}

}