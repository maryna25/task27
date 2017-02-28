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
		static Volume volume(pow);
		return volume;
	}

	void increase(int plusVolume=1)
	{
		power += plusVolume;
	}

	void decrease(int minusVolume=1)
	{
		power -= minusVolume;
	}

    int get() const 
	{
		return power;
	}

};