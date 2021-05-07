// By: Oliver Ngong and Precious Njeck
#include <math.h>

class Rectblocks {
    public:
    	double Width;
    	double Height;
    	double Length;
    	Rectblocks(double _Width, double _Height, double _Length){
		Width = _Width;
		Height = _Height;
		Length = _Length;
		}
};

class SqrBaseRectBlocks : public Rectblocks {
    public:
    	SqrBaseRectBlocks(double _Width, double _Height, double _Length) : Rectblocks{_Width, _Height, _Length}{
		}
};

class CubiodBlocks : public SqrBaseRectBlocks {
    public:
    	CubiodBlocks(double W, double H, double L) : SqrBaseRectBlocks(W, H, L){
		}
};

class CylindricalBlocks : public SqrBaseRectBlocks {
    public:
    	double Diameter;
		double CSA;
		double Area;
    	CylindricalBlocks(double Width, double Height, double Length): SqrBaseRectBlocks(Width, Height, Length){
			Diameter = Height;
			CSA = (2 * M_PI * Height * Height) * 2;
			Area = M_PI * Height * Height;
		}
};

class SphericalBlocks : public CubiodBlocks{
    public:
    	double Diameter;
		double SphericalSA;
		double Volume;
    	SphericalBlocks(double Width, double Height, double Length): CubiodBlocks{Width, Height, Length}{
			Diameter = Length;
			SphericalSA = M_PI * Length * Length;
			Volume = (M_PI * Length * Length * Length) / 6;
		}
};
