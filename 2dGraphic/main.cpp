#include "GameLib/Framework.h"

namespace GameLib {
	void Framework::update() {
		unsigned* vram = videoMemory();

		int _width = width();

		for (int i = 100; i <= 200; ++i)
		{
			for (int j = 100; j <= 200; ++j)
			{
				vram[j * _width + i] = 0xff0000;
			}
		}
		//vram[200 * width() + 100] = 0xff0000;

		/*
		
		static unsigned i;
		vram[i] += i * 100;
		i += 9973; //1–œˆÈ‰ºÅ‘å‚Ì‘f”
		i %= (width() * height());
		*/
	}
}