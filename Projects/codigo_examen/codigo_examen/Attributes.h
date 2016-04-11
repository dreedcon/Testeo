#ifndef _ATTRIBUTES_H_
#define _ATTRIBUTES_H_


class Attributes
{

private:

	//propiertes
	int level = 1;
	int hpMax = 0;
	int stamMax = 0;
	int furyMax = 0;
	int lvlMax = 0;
	int damage = 0;

	int currentExp = 0;
	int expRequired = 50;

	//propierties * lvl
	int expLvl = 20;
	int hpLvl = 0;
	int stamLvl = 0;
	int furyLvl = 0;

public:

	//constructors
	Attributes(){}

	//assignment constructor
	Attributes(int baseHp, int basestam, int baseFury, int baseDamage, int _hpLvl, int _stamLvl, int _furyLvl, int _lvlMax){ hpMax = baseHp; stamMax = basestam; furyMax = baseFury; damage = baseDamage; hpLvl = _hpLvl; stamLvl = _stamLvl; furyLvl = _furyLvl; lvlMax = _lvlMax; }

	//copy constructor
	Attributes(Attributes& atr){ this->hpMax = atr.hpMax; this->stamMax = atr.stamMax; this->furyMax = atr.furyMax; this->lvlMax = atr.lvlMax; this->damage = atr.damage; this->currentExp = atr.currentExp; this->hpLvl = atr.hpLvl; this->stamLvl = atr.stamLvl; this->furyLvl = atr.furyLvl; }

	//methods
	void gainExp(int exp)
	{
		currentExp += exp;
	}

	const int whatIsyourExp()
	{
		return currentExp;
	}

};


#endif