#pragma once

class Volume
{
	int power;
private:
	Volume(int pow) :power{pow}
	{};
public: 
	Volume(const Volume&) = delete;
	Volume() = delete;

	Volume& operator=(const Volume&) = delete;

	static Volume& set(int pow =0)
	{
		if (pow > 0)
		{
			static Volume volume(pow);
			return volume;
		}
		else
		{
			static Volume volume(0);
			return volume;
		}
	}

	void increase(int plusVolume=1)
	{
		power += plusVolume;
	}

	void decrease(int minusVolume=1)
	{
		if (power-minusVolume >=0) power -= minusVolume;
		else power = 0;
	}

    int get() const 
	{
		return power;
	}

};