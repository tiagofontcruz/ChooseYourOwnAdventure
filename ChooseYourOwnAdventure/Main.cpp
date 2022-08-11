#include<iostream>
#include<random>
#include<string>
#include<dos.h>

using namespace std;

std::mt19937 rng;

//global variable
int page = 0;
string skillName;
const int SKILL_HIT = 20; // ((SKILL_HIT * str) + (random number 0-8 * dex)
const int NORMAL_HIT = 5; // ((NORMAL_HIT * str) + (random number 0-8 * dex)
const int MONSTER_HIT = 15; // ((MONSTER_HIT) * (random number 0-8)
int hp = 100; //full hp and regen is multiplied by con
int mp = 100; //full mp and regen is multiplied by intel
int str; //used to normal hit and skill hit
int dex; //used to normal hit and skill hit
int con; //used to full hp and regen
int intel; //used to full mp and regen
int wis; //used to mp consumption

//doors health points
const int HP_SIMPLE_WOODEN_DOOR = 1000;
const int HP_GOOD_WOODEN_DOOR = 1500;
const int HP_STRONG_WOODEN_DOOR = 2000;
const int HP_IRON_PORTCULLIS = 4000;

//monsters health points
const int HP_MONSTROUS_SPIDER = 2000;
const int HP_SPIDER_SWARM = 1500;
const int HP_DIRE_RAT = 1000;
const int HP_WARRIOR_SVIRFNEBLIN = 3000;
const int HP_WARRIOR_DUERGAR = 2200;

//function prototypes
int Page00(); //screen 01 (intro)
int Page01(); //screen 02 (character Barbarian)
int Page02(); //screen 03 (character Ranger)
int Page03(); //screen 04 (character Paladin)
int Room01(); //screen 05 (entrance that goes to rooms 02;03)
int Room02(); //screen 06 (room with doors that goes to rooms 04;12)
int Room03(); //screen 07 (room with doors that goes to rooms 10;11)
int Room04(); //screen 08 (room with doors that goes to rooms 12;14)
int Room05(); //screen 09 (room with a door that goes to room 13)
int Room06(); //screen 10 (monster room with a door that goes to room 15)
int Room07(); //screen 11 (room with a door that goes to room 09)
int Room08(); //screen 12 (room with a trap for those who came from room 16)
int Room09(); //screen 13 (room with a door that goes to room 05)
int Room10(); //screen 14 (monster room with a door that goes to room 06)
int Room11(); //screen 15 (monster room with a door that goes to room 07)
int Room12(); //screen 16 (monster room with doors that goes to rooms 13;16)
int Room13(); //screen 17 (room with a door that goes to exit room 17)
int Room14(); //screen 18 (room with a trap for those who came from room 04)
int Room15(); //screen 19 (room with a door that goes to exit room 17)
int Room16(); //screen 20 (room with a door that goes to room 08)

int hittingDoors(int choice, int door) {

	do
	{
		//give player choices
		std::cout << "Will you try to break down the door with a normal hit (1) or using " << skillName << " skill (2) ? ";
		std::cin >> choice;

		//validate player input
		if (choice != 1 && choice != 2)
		{
			std::cout << "That is not an option. Try again." << std::endl;
		}
		else
		{
			system("cls");

			if (choice == 1)
			{
				//damage with normal hit
				std::uniform_int_distribution<unsigned int> uint_dist10(0, 8);
				int hit = (NORMAL_HIT * str) + (uint_dist10(rng) * dex); //hit power
				if (hit > 140)
				{
					std::cout << "You hit the door causing " << hit << " points of a critical damage." << std::endl;
				}
				else
				{
					std::cout << "You hit the door causing " << hit << " points of damage." << std::endl;
				}
				door -= hit;
				if (door > 0)
				{
					std::cout << "Now the door has " << door << " points of HP." << std::endl;
				}
				else
				{
					std::cout << "You have broken the door!" << std::endl;
				}
				std::cout << "" << std::endl;
			}
			else
			{
				//test if MP is enough
				if (mp > (SKILL_HIT * wis))
				{
					//damage with skill hit
					std::uniform_int_distribution<unsigned int> uint_dist10(0, 8);
					int skill = (SKILL_HIT * str) + (uint_dist10(rng) * dex); //skill power							
					mp -= SKILL_HIT * wis; //MP consumption

					//test if is critical damage
					if (skill > 250)
					{
						std::cout << "You hit the door with the " << skillName << " skill, causing " << skill << " points of a critical damage." << std::endl;
					}
					else
					{
						std::cout << "You hit the door with the " << skillName << " skill, causing " << skill << " points of damage." << std::endl;
					}
					std::cout << "Now your have " << mp << " points of MP." << std::endl;
					door -= skill; //door damage

					//test if door has broken
					if (door > 0)
					{
						std::cout << "Now the door has " << door << " points of HP." << std::endl;
					}
					else
					{
						std::cout << "You have broken the door!" << std::endl;
					}
					std::cout << "" << std::endl;
				}
				else
				{
					std::cout << "Your MP is not enough!" << std::endl;
				}
			}
		}
	} while (choice != 1 && choice != 2 || door > 0);
	return door;
}

int hittingMechanicalTriggers(int choice, int door) {

	do
	{
		//give player choices
		std::cout << "Will you try to break down the mechanical trigger with a normal hit (1) or using " << skillName << " skill (2) ? ";
		std::cin >> choice;

		//validate player input
		if (choice != 1 && choice != 2)
		{
			std::cout << "That is not an option. Try again." << std::endl;
		}
		else
		{
			system("cls");

			if (choice == 1)
			{
				//damage with normal hit
				std::uniform_int_distribution<unsigned int> uint_dist10(0, 8);
				int hit = (NORMAL_HIT * str) + (uint_dist10(rng) * dex); //hit power
				if (hit > 140)
				{
					std::cout << "You hit the mechanical trigger causing " << hit << " points of a critical damage." << std::endl;
				}
				else
				{
					std::cout << "You hit the mechanical trigger causing " << hit << " points of damage." << std::endl;
				}
				door -= hit;
				if (door > 0)
				{
					std::cout << "Now the mechanical trigger has " << door << " points of HP." << std::endl;
				}
				else
				{
					std::cout << "You have broken the mechanical trigger!" << std::endl;
				}
				std::cout << "" << std::endl;
			}
			else
			{
				//test if MP is enough
				if (mp > (SKILL_HIT * wis))
				{
					//damage with skill hit
					std::uniform_int_distribution<unsigned int> uint_dist10(0, 8);
					int skill = (SKILL_HIT * str) + (uint_dist10(rng) * dex); //skill power							
					mp -= SKILL_HIT * wis; //MP consumption

					//test if is critical damage
					if (skill > 250)
					{
						std::cout << "You hit the mechanical trigger with the " << skillName << " skill, causing " << skill << " points of a critical damage." << std::endl;
					}
					else
					{
						std::cout << "You hit the mechanical trigger with the " << skillName << " skill, causing " << skill << " points of damage." << std::endl;
					}
					std::cout << "Now your have " << mp << " points of MP." << std::endl;
					door -= skill; //door damage

					//test if door has broken
					if (door > 0)
					{
						std::cout << "Now the mechanical trigger has " << door << " points of HP." << std::endl;
					}
					else
					{
						std::cout << "You have broken the mechanical trigger!" << std::endl;
					}
					std::cout << "" << std::endl;
				}
				else
				{
					std::cout << "Your MP is not enough!" << std::endl;
				}
			}
		}
	} while (choice != 1 && choice != 2 || door > 0);
	return door;
}

void hittingMonster(int choice, int monsterHP, string monsterName) {
	do
	{
		//give player choices
		std::cout << "Will you try to attack the " << monsterName << " with a normal hit(1) or using " << skillName << " skill(2) ? ";
		std::cin >> choice;

		//validate player input
		if (choice != 1 && choice != 2)
		{
			std::cout << "That is not an option. Try again." << std::endl;
		}
		else
		{
			system("cls");
			if (choice == 1)
			{
				std::uniform_int_distribution<unsigned int> uint_dist10(0, 8);
				int hit = (NORMAL_HIT * str) + (uint_dist10(rng) * dex);
				if (hit > 140)
				{
					std::cout << "You hit the " << monsterName << " causing " << hit << " points of a critical damage." << std::endl;
				}
				else
				{
					std::cout << "You hit the " << monsterName << " causing " << hit << " points of damage." << std::endl;
				}
				monsterHP -= hit;
				int monsterHit = MONSTER_HIT * uint_dist10(rng); //monster hit power
				hp -= monsterHit;

				if (hp <= 0)
				{
					std::cout << "You died!!!" << std::endl;
					system("pause");
					exit(-1);
				}
				if (monsterHP > 0)
				{
					std::cout << "Now the " << monsterName << " has " << monsterHP << " points of HP." << std::endl;
					std::cout << "Now you have " << hp << " points of HP." << std::endl;
				}
				else
				{
					std::cout << "You have killed the " << monsterName << " !" << std::endl;
				}
				std::cout << "" << std::endl;
			}
			else
			{
				//test if MP is enough
				if (mp > (SKILL_HIT * wis))
				{
					std::uniform_int_distribution<unsigned int> uint_dist10(0, 8);
					int skill = (SKILL_HIT * str) + (uint_dist10(rng) * dex); //skill power							
					mp -= SKILL_HIT * wis; //MP consume
					if (skill > 250)
					{
						std::cout << "You hit the " << monsterName << " with the " << skillName << " skill, causing " << skill << " points of a critical damage." << std::endl;
					}
					else
					{
						std::cout << "You hit the " << monsterName << " with the " << skillName << " skill, causing " << skill << " points of damage." << std::endl;
					}
					std::cout << "Now your have " << mp << " points of MP." << std::endl;
					monsterHP -= skill;
					int monsterHit = MONSTER_HIT * uint_dist10(rng); //monster hit power
					hp -= monsterHit;
					if (hp <= 0)
					{
						std::cout << "You died!!!" << std::endl;
						system("pause");
						exit(-1);
					}
					if (monsterHP > 0)
					{
						std::cout << "Now the " << monsterName << " has " << monsterHP << " points of HP." << std::endl;
						std::cout << "Now you have " << hp << " points of HP." << std::endl;
					}
					else
					{
						std::cout << "You have killed the " << monsterName << " !" << std::endl;
					}
					std::cout << "" << std::endl;
				}
				else
				{
					std::cout << "Your MP is not enough!" << std::endl;
				}
			}
		}
	} while (choice != 1 && choice != 2 || monsterHP > 0 && hp > 0);
}

void hittingMonsters(int choice, int monsterHP, string monsterName, int enemyNumber) {
	do
	{
		//give player choices
		std::cout << "Will you try to attack the " << monsterName << " with a normal hit(1) or using " << skillName << " skill(2) ? ";
		std::cin >> choice;

		//validate player input
		if (choice != 1 && choice != 2)
		{
			std::cout << "That is not an option. Try again." << std::endl;
		}
		else
		{
			system("cls");
			if (choice == 1)
			{
				std::uniform_int_distribution<unsigned int> uint_dist10(0, 8);
				int hit = (NORMAL_HIT * str) + (uint_dist10(rng) * dex);
				if (hit > 140)
				{
					std::cout << "You hit the " << monsterName << " causing " << hit << " points of a critical damage." << std::endl;
				}
				else
				{
					std::cout << "You hit the " << monsterName << " causing " << hit << " points of damage." << std::endl;
				}
				monsterHP -= hit;
				int monsterHit = MONSTER_HIT * uint_dist10(rng); //monster hit power
				hp -= monsterHit;
				if (hp <= 0)
				{
					std::cout << "You died!!!" << std::endl;
					system("pause");
					exit(-1);
				}
				if (monsterHP > 0)
				{
					std::cout << "Now the " << monsterName << " has " << monsterHP << " points of HP." << std::endl;
					std::cout << "Now you have " << hp << " points of HP." << std::endl;
				}
				else
				{
					std::cout << "You have killed the " << monsterName << " !" << std::endl;
					enemyNumber -= 1;
					if (enemyNumber == 1)
					{
						monsterHP = HP_DIRE_RAT;
					}
				}
				std::cout << "" << std::endl;
			}
			else
			{
				//test if MP is enough
				if (mp > (SKILL_HIT * wis))
				{
					std::uniform_int_distribution<unsigned int> uint_dist10(0, 8);
					int skill = (SKILL_HIT * str) + (uint_dist10(rng) * dex); //skill power							
					mp -= SKILL_HIT * wis; //MP consume
					if (skill > 250)
					{
						std::cout << "You hit the " << monsterName << " with the " << skillName << " skill, causing " << skill << " points of a critical damage." << std::endl;
					}
					else
					{
						std::cout << "You hit the " << monsterName << " with the " << skillName << " skill, causing " << skill << " points of damage." << std::endl;
					}
					std::cout << "Now your have " << mp << " points of MP." << std::endl;
					monsterHP -= skill;
					int monsterHit = MONSTER_HIT * uint_dist10(rng); //monster hit power
					hp -= monsterHit;
					if (hp <= 0)
					{
						std::cout << "You died!!!" << std::endl;
						system("pause");
						exit(-1);
					}
					if (monsterHP > 0)
					{
						std::cout << "Now the " << monsterName << " has " << monsterHP << " points of HP." << std::endl;
						std::cout << "Now you have " << hp << " points of HP." << std::endl;
					}
					else
					{
						std::cout << "You have killed the " << monsterName << " !" << std::endl;
						enemyNumber -= 1;
						if (enemyNumber == 1)
						{
							monsterHP = HP_DIRE_RAT;
						}
					}
					std::cout << "" << std::endl;
				}
				else
				{
					std::cout << "Your MP is not enough!" << std::endl;
				}
			}
		}
	} while (choice != 1 && choice != 2 || monsterHP > 0 && enemyNumber >= 1 && hp > 0);
}

void main()
{
	//seed the RNG.
	std::random_device rd;
	rng.seed(rd());

	//game title
	std::cout << "           IIIIIIIIIIIIIII The Shrine of Dismal Secrets IIIIIIIIIIIIIII" << std::endl;
	std::cout << "" << std::endl;

	//instructions about the game
	std::cout << "" << std::endl;
	std::cout << "             INSTRUCTIONS:" << std::endl;
	std::cout << "" << std::endl;
	std::cout << "- The game will ask number 1 or 2 to choose and ENTER to confirm." << std::endl;
	std::cout << "- The dungeon has several rooms." << std::endl;
	std::cout << "- You must choose where to go." << std::endl;
	std::cout << "- You will have to break doors, may face creatures or die in a trap." << std::endl;
	std::cout << "- Each room that you pass, your HP and MP will restore a little." << std::endl;
	std::cout << "- HP restoration is based in CON attribute." << std::endl;
	std::cout << "- MP restoration is based in INT attribute." << std::endl;
	std::cout << "- MP consumption is based in WIS attribute." << std::endl;
	std::cout << "- Damage is based in STR and DEX attributes." << std::endl;
	std::cout << "- Choose your character wisely, according to your play style." << std::endl;
	std::cout << "" << std::endl;
	system("pause");
	system("cls");

	do //main event loop of the game	
	{
		switch (page)
		{
		case 0: //character selection
			page = Page00();
			system("cls");
			break;
		case 1: //set attributes
			page = Page01();
			system("pause");
			system("cls");
			break;
		case 2: //set attributes
			page = Page02();
			system("pause");
			system("cls");
			break;
		case 3: //set attributes
			page = Page03();
			system("pause");
			system("cls");
			break;
		case 101: //room's start
			page = Room01();
			system("pause");
			system("cls");
			break;
		case 102:
			page = Room02();
			system("cls");
			break;
		case 103:
			page = Room03();
			system("cls");
			break;
		case 104:
			page = Room04();
			system("cls");
			break;
		case 105:
			page = Room05();
			system("cls");
			break;
		case 106:
			page = Room06();
			system("cls");
			break;
		case 107:
			page = Room07();
			system("cls");
			break;
		case 108:
			page = Room08();
			system("cls");
			break;
		case 109:
			page = Room09();
			system("cls");
			break;
		case 110:
			page = Room10();
			system("cls");
			break;
		case 111:
			page = Room11();
			system("cls");
			break;
		case 112:
			page = Room12();
			system("cls");
			break;
		case 113:
			page = Room13();
			system("cls");
			break;
		case 114:
			page = Room14();
			system("cls");
			break;
		case 115:
			page = Room15();
			system("cls");
			break;
		case 116:
			page = Room16();
			system("cls");
			break;
		case 117: //last room (exit)
			std::cout << "                   CONGRATULATIONS!!!" << std::endl;
			std::cout << "   YOU DEFEAT MONSTERS AND SCAPE FROM THE DUNGEON!!!" << std::endl;
			std::cout << "                      WELL DONE!!!" << std::endl;
			std::cout << "" << std::endl;
			std::cout << "IF YOU WANT, YOU CAN PLAY AGAIN WITH ANOTHER CHARACTER!!!" << std::endl;
			system("pause");
			exit(-1);
			break;
		default:
			std::cout << "                   YOU DIED!!!" << std::endl;
			std::cout << "                    GAME OVER" << std::endl;
			system("pause");
			exit(-1);
		}
	} while (page != -1);
}

//character selection
int Page00()
{
	bool done = false;
	int page;
	do
	{
		//print description
		std::cout << "           IIIIIIIIIIIIIII Choose your character IIIIIIIIIIIIIII" << std::endl;
		std::cout << "***************************************************************************************" << std::endl;
		std::cout << "*  Wynna: Female Human Barbarian                                                      *" << std::endl;
		std::cout << "*  Attributes: Str 17 | Dex 9 | Con 13 | Int 8 | Wis 6                                *" << std::endl;
		std::cout << "*  Description: Wynna is heavyset, with copper hair and bright blue eyes.             *" << std::endl;
		std::cout << "*               She wears scale mail and wields a battleaxe.                          *" << std::endl;
		std::cout << "*               Wynna has an animal companion, a black dog named Sige.                *" << std::endl;
		std::cout << "***************************************************************************************" << std::endl;

		std::cout << "" << std::endl;
		std::cout << "***************************************************************************************" << std::endl;
		std::cout << "*  Arryn: Male Human Ranger                                                           *" << std::endl;
		std::cout << "*  Attributes: Str 12 | Dex 11 | Con 9 | Int 10 | Wis 8                               *" << std::endl;
		std::cout << "*  Description: Arryn is common in appearance, with grey hair and hazel eyes.         *" << std::endl;
		std::cout << "*               He wears leather armor and longbow.                                   *" << std::endl;
		std::cout << "*               Arryn seeks to prove himself to his peers.                            *" << std::endl;
		std::cout << "***************************************************************************************" << std::endl;

		std::cout << "" << std::endl;
		std::cout << "***************************************************************************************" << std::endl;
		std::cout << "*  Adow: Female Human Paladin                                                         *" << std::endl;
		std::cout << "*  Attributes: Str 14 | Dex 10 | Con 15 | Int 12 | Wis 10                             *" << std::endl;
		std::cout << "*  Description: Adow is exceptionally beautiful, with auburn hair and soft amber eyes.*" << std::endl;
		std::cout << "*               She wears hide armor and wields a scimitar.                           *" << std::endl;
		std::cout << "*               Adow is capable and cheerful.                                         *" << std::endl;
		std::cout << "***************************************************************************************" << std::endl;

		//give player choices
		std::cout << "Choose your character (press 1 for Barbarian - 2 for Ranger - 3 for Paladin): ";
		std::cin >> page;
		std::cout << "" << std::endl;

		//validate player input
		if (page >= 1 && page <= 3)
		{
			done = true;
		}
		else
		{
			std::cout << "You need to choose an option from 1 to 3." << std::endl;
			std::cout << "" << std::endl;
		}
	} while (!done);
	return page;
}

//set Barbarian attributes
int Page01()
{
	int page = 101;
	//shows the character's name and skill name
	std::cout << "You chose the Barbarian Wynna!" << std::endl;
	std::cout << "" << std::endl;
	skillName = "Shockwave";
	str = 17;
	dex = 9;
	con = 13;
	intel = 8;
	wis = 6;
	hp = hp * con;
	mp = mp * intel;
	//shows the health and mana initial status
	std::cout << "Skill: " << skillName << std::endl;
	std::cout << "Your HP is " << hp << " points" << std::endl;
	std::cout << "Your MP is " << mp << " points" << std::endl;
	std::cout << "" << std::endl;
	return page;
}

//set Ranger attributes
int Page02()
{
	int page = 101;
	//shows the character's name and skill name
	std::cout << "You chose the Ranger Arryn!" << std::endl;
	std::cout << "" << std::endl;
	skillName = "Power Shot";
	str = 12;
	dex = 11;
	con = 9;
	intel = 10;
	wis = 8;
	hp = hp * con;
	mp = mp * intel;
	//shows the health and mana initial status
	std::cout << "Skill: " << skillName << std::endl;
	std::cout << "Your HP is " << hp << " points" << std::endl;
	std::cout << "Your MP is " << mp << " points" << std::endl;
	std::cout << "" << std::endl;
	return page;
}

//set Paladin attributes
int Page03()
{
	int page = 101;
	//shows the character's name and skill name
	std::cout << "You chose the Paladin Adow!" << std::endl;
	std::cout << "" << std::endl;
	skillName = "Judgement";
	str = 14;
	dex = 10;
	con = 15;
	intel = 12;
	wis = 10;
	hp = hp * con;
	mp = mp * intel;
	//shows the health and mana initial status
	std::cout << "Skill: " << skillName << std::endl;
	std::cout << "Your HP is " << hp << " points" << std::endl;
	std::cout << "Your MP is " << mp << " points" << std::endl;
	std::cout << "" << std::endl;
	return page;
}

//page 101
int Room01()
{
	//setting variables
	bool done = false;
	int choice = -1;
	int page = -1;
	int door = HP_SIMPLE_WOODEN_DOOR;

	//game intro
	std::cout << "************************************************************************************************************" << std::endl;
	std::cout << "*  The dungeon was created by worshippers of a good deity as a shrine.                                     *" << std::endl;
	std::cout << "*  It was eventually conquered by invaders, and has fallen to ruin and been rebuilt many times since then. *" << std::endl;
	std::cout << "*  Are you ready to scape of this condemned place?                                                         *" << std::endl;
	std::cout << "************************************************************************************************************" << std::endl;
	std::cout << "" << std::endl;

	//give player choices
	std::cout << "" << std::endl;
	std::cout << "Press (1) to say Yes, and (2) to say No: ";
	std::cin >> choice;

	//validate player input
	if (choice != 1)
	{
		//will leave the adventure
		std::cout << "" << std::endl;
		std::cout << "Well... comeback to play when you are ready!" << std::endl;
		system("pause");
		exit(-1);
	}
	else
	{
		//will start the adventure
		std::cout << "" << std::endl;
		std::cout << "The adventure will start now!!!!" << std::endl;
		std::cout << "You woke up lying on the floor in the middle of the mountains inside The Shrine of Dismal Secrets." << std::endl;
		std::cout << "You don't remember how you got into that rounded room." << std::endl;
		std::cout << "The room is empty, but there are two simple wooden doors." << std::endl;
		std::cout << "One door on northern entrance and one on western entrance." << std::endl;		
		std::cout << "Luckily, your weapon is on your side." << std::endl;
		std::cout << "" << std::endl;

		do
		{
			//give player choices
			std::cout << "Now you need to decide whether to go to the northern (1) or western entrance (2): ";
			std::cin >> page;

			//validate player input
			if (page == 1)
			{
				page = 102;
				done = true;
			}
			else
			{
				if (page == 2)
				{
					page = 103;
					done = true;
				}
				else
				{
					std::cout << "You must to choose option 1 or 2." << std::endl;
					std::cout << "" << std::endl;
				}
			}
		} while (!done);
		system("cls");

		//shows the health and mana status
		std::cout << "Your HP is " << hp << " points" << std::endl;
		std::cout << "Your MP is " << mp << " points" << std::endl;
		std::cout << "" << std::endl;
		do
		{
			//give player choices
			std::cout << "Do you will break the door (1) or try to open (2)? ";
			std::cin >> choice;

			//validate player input
			if (choice != 1 && choice != 2)
			{
				std::cout << "That is not an option. Try again." << std::endl;
			}
		} while (choice != 1 && choice != 2);
		system("cls");
	}

	do {
		switch (choice)
		{
		case 1: //call a function to break the door		
			std::cout << "" << std::endl;
			door = hittingDoors(choice, door);
			break;
		case 2:
			std::cout << "" << std::endl;
			std::cout << "The door is locked! Try to break it!" << std::endl;
			choice = 1;
		}
	} while (door > 0);
	return page;
}

//page 102
int Room02()
{
	bool done = false;
	int choice = -1;
	int page = -1;
	int door = HP_GOOD_WOODEN_DOOR;
	mp += 10 * intel;
	hp += 15 * con;

	std::cout << "" << std::endl;
	std::cout << "You decided to go to the northern entrance and you passed the first rounded room." << std::endl;
	std::cout << "The room is empty with a bad smell." << std::endl;
	std::cout << "There is a good wooden door located on the eastern entrance." << std::endl;
	std::cout << "" << std::endl;

	//shows the health and mana status
	std::cout << "Your HP is " << hp << " points" << std::endl;
	std::cout << "Your MP is " << mp << " points" << std::endl;
	std::cout << "" << std::endl;
	do
	{
		std::cout << "Do you will break the door (1) or try to open (2) ? ";
		std::cin >> choice;
		if (choice != 1 && choice != 2)
		{
			std::cout << "That is not an option. Try again." << std::endl;
		}
	} while (choice != 1 && choice != 2);
	system("cls");

	do {
		switch (choice)
		{
		case 1: //call a function to break the door		
			std::cout << "" << std::endl;
			door = hittingDoors(choice, door);
			break;
		case 2:
			std::cout << "" << std::endl;
			std::cout << "The door is locked! Try to break it!" << std::endl;
			choice = 1;
		}
	} while (door > 0);


	do
	{
		//give player choices
		std::cout << "Now you have to go down straight to the corridor." << std::endl;
		std::cout << "Decide whether you will enter the corridor, at the northern (1) or southern entrance (2): ";
		std::cin >> page;

		//validate player input
		if (page == 1)
		{
			page = 112;
			done = true;
		}
		else
		{
			if (page == 2)
			{
				page = 104;
				done = true;
			}
			else
			{
				std::cout << "You need to choose option 1 or 2." << std::endl;
				std::cout << "" << std::endl;
			}
		}
	} while (!done);
	return page;
}

//page 103
int Room03()
{
	bool done = false;
	int choice = -1;
	int door = HP_GOOD_WOODEN_DOOR;
	mp += 10 * intel;
	hp += 15 * con;

	std::cout << "" << std::endl;
	std::cout << "You decided to go to the western entrance and you passed the first rounded room." << std::endl;
	std::cout << "The room is empty, but there is simple wooden door on the southern entrance." << std::endl;
	std::cout << "The other simple wooden door is located on the east above a small stone dais" << std::endl;
	std::cout << "and concealed within a mosaic of ghoulish carnage." << std::endl;
	std::cout << "" << std::endl;

	//shows the health and mana status
	std::cout << "Your HP is " << hp << " points" << std::endl;
	std::cout << "Your MP is " << mp << " points" << std::endl;
	std::cout << "" << std::endl;

	do //decide the room
	{
		std::cout << "Now you need to decide whether to go to the eastern (1) or southern entrance (2): ";
		std::cin >> page;
		if (page == 1)
		{
			page = 110;
			done = true;
		}
		else
		{
			if (page == 2)
			{
				page = 111;
				done = true;
			}
			else
			{
				std::cout << "You need to choose option 1 or 2." << std::endl;
				std::cout << "" << std::endl;
			}
		}
	} while (!done);
	do
	{
		std::cout << "Do you will break (1) or try to open (2)? ";
		std::cin >> choice;
		if (choice != 1 && choice != 2)
		{
			std::cout << "That is not an option. Try again." << std::endl;
		}
	} while (choice != 1 && choice != 2);
	system("cls");

	do {
		switch (choice)
		{
		case 1: //call a function to break the door		
			std::cout << "" << std::endl;
			door = hittingDoors(choice, door);
			break;
		case 2:
			std::cout << "" << std::endl;
			std::cout << "The door is locked! Try to break it!" << std::endl;
			choice = 1;
		}
	} while (door > 0);
	return page;
}

//page 104
int Room04()
{
	bool done = false;
	int choice = -1;
	int door = HP_IRON_PORTCULLIS;
	mp += 10 * intel;
	hp += 15 * con;

	std::cout << "" << std::endl;
	std::cout << "You decided to go to the southern entrance." << std::endl;
	std::cout << "The room is empty, but there is a trapped iron portcullis on the southern entrance." << std::endl;
	std::cout << "You must break the mechanical trigger to elevate the iron portcullis!" << std::endl;
	std::cout << "" << std::endl;

	//shows the health and mana status
	std::cout << "Your HP is " << hp << " points" << std::endl;
	std::cout << "Your MP is " << mp << " points" << std::endl;
	std::cout << "" << std::endl;

	//call a function to break the mechanical trigger			
	door = hittingMechanicalTriggers(choice, door);

	//decide the room
	std::cout << "Well done! Now you must go to next room in the southen entrance.";
	page = 114;
	return page;
}

//page 105
int Room05()
{
	bool done = false;
	int choice = -1;
	int page = -1;
	int door = HP_STRONG_WOODEN_DOOR;
	mp += 10 * intel;
	hp += 15 * con;

	std::cout << "" << std::endl;
	std::cout << "You've reached the south entrance room." << std::endl;
	std::cout << "The room is empty." << std::endl;
	std::cout << "There is a stuck strong wooden door located on the southen entrance." << std::endl;
	std::cout << "" << std::endl;

	//shows the health and mana status
	std::cout << "Your HP is " << hp << " points" << std::endl;
	std::cout << "Your MP is " << mp << " points" << std::endl;
	std::cout << "" << std::endl;
	do
	{
		std::cout << "Do you will break the door (1) or try to open (2) ? ";
		std::cin >> choice;
		if (choice != 1 && choice != 2)
		{
			std::cout << "That is not an option. Try again." << std::endl;
		}
	} while (choice != 1 && choice != 2);
	system("cls");

	do {
		switch (choice)
		{
		case 1: //call a function to break the door		
			std::cout << "" << std::endl;
			door = hittingDoors(choice, door);
			break;
		case 2:
			std::cout << "" << std::endl;
			std::cout << "The door is locked! Try to break it!" << std::endl;
			choice = 1;
		}
	} while (door > 0);
	std::cout << "Now you must run to the eastern entrance.";
	page = 113;
	return page;
}

//page 106
int Room06()
{
	bool done = false;
	int choice = -1;
	int monsterHP = HP_WARRIOR_DUERGAR;
	mp += 10 * intel;
	hp += 15 * con;

	std::cout << "" << std::endl;
	std::cout << "You've reached the western entrance room." << std::endl;
	std::cout << "The floor is covered in square tiles, alternating white and black, and a large demonic idol" << std::endl;
	std::cout << "with ruby eyes sits in the south-west corner of the room." << std::endl;
	std::cout << "The room has a warrior Duergar and he is coming for you!" << std::endl;
	std::cout << "" << std::endl;

	//shows the health and mana status
	std::cout << "Your HP is " << hp << " points" << std::endl;
	std::cout << "Your MP is " << mp << " points" << std::endl;
	std::cout << "" << std::endl;

	//call a function to hit the monster
	hittingMonster(choice, monsterHP, "warrior Duergar");
	std::cout << "You must run through the corridor and enter into another room!" << std::endl;
	page = 115;
	return page;
}

//page 107
int Room07()
{
	bool done = false;
	int choice = -1;
	int page = -1;
	int door = HP_SIMPLE_WOODEN_DOOR;
	mp += 10 * intel;
	hp += 15 * con;

	std::cout << "" << std::endl;
	std::cout << "You've reached the north entrance room." << std::endl;
	std::cout << "The room is empty." << std::endl;
	std::cout << "There is a simple wooden door located on the southen entrance." << std::endl;
	std::cout << "" << std::endl;

	//shows the health and mana status
	std::cout << "Your HP is " << hp << " points" << std::endl;
	std::cout << "Your MP is " << mp << " points" << std::endl;
	std::cout << "" << std::endl;
	do
	{
		std::cout << "Do you will break the door (1) or try to open (2) ? ";
		std::cin >> choice;
		if (choice != 1 && choice != 2)
		{
			std::cout << "That is not an option. Try again." << std::endl;
		}
	} while (choice != 1 && choice != 2);
	system("cls");

	do {
		switch (choice)
		{
		case 1: //call a function to break the door		
			std::cout << "" << std::endl;
			door = hittingDoors(choice, door);
			break;
		case 2:
			std::cout << "" << std::endl;
			std::cout << "The door is locked! Try to break it!" << std::endl;
			choice = 1;
		}
	} while (door > 0);

	std::cout << "Now you must run to the easten entrance.";
	page = 109;
	return page;
}

//page 108
int Room08()
{
	std::cout << "           IT'S A TRAP!!!!" << std::endl;
	std::cout << "In this room you fell into a trap!!!" << std::endl;
	system("pause");
	int page = -2;
	return page;
}

//page 109
int Room09()
{
	bool done = false;
	int choice = -1;
	int page = -1;
	int door = HP_SIMPLE_WOODEN_DOOR;
	mp += 10 * intel;
	hp += 15 * con;

	std::cout << "" << std::endl;
	std::cout << "You've reached the west entrance room." << std::endl;
	std::cout << "A faded and torn tapestry hangs from the east wall, and a charred wooden shield lies in the center of the room." << std::endl;
	std::cout << "There is a stuck simple sooden door located on the southen entrance." << std::endl;
	std::cout << "" << std::endl;

	//shows the health and mana status
	std::cout << "Your HP is " << hp << " points" << std::endl;
	std::cout << "Your MP is " << mp << " points" << std::endl;
	std::cout << "" << std::endl;
	do
	{
		std::cout << "Do you will break the door (1) or try to open (2) ? ";
		std::cin >> choice;
		if (choice != 1 && choice != 2)
		{
			std::cout << "That is not an option. Try again." << std::endl;
		}
	} while (choice != 1 && choice != 2);
	system("cls");

	do {
		switch (choice)
		{
		case 1: //call a function to break the door		
			std::cout << "" << std::endl;
			door = hittingDoors(choice, door);
			break;
		case 2:
			std::cout << "" << std::endl;
			std::cout << "The door is locked! Try to break it!" << std::endl;
			choice = 1;
		}
	} while (door > 0);

	std::cout << "Now you must run to the north entrance.";
	page = 105;
	return page;
}

//page 110
int Room10()
{
	bool done = false;
	int choice = -1;
	int door = HP_SIMPLE_WOODEN_DOOR;
	int monsterHP = HP_SPIDER_SWARM;
	mp += 10 * intel;
	hp += 15 * con;

	std::cout << "" << std::endl;
	std::cout << "You decided to go to the western entrance." << std::endl;
	std::cout << "The room has a spider swarm! You must attack!" << std::endl;
	std::cout << "" << std::endl;

	//shows the health and mana status
	std::cout << "Your HP is " << hp << " points" << std::endl;
	std::cout << "Your MP is " << mp << " points" << std::endl;
	std::cout << "" << std::endl;

	//call a function that hits a monster
	hittingMonster(choice, monsterHP, "spider swarm");
	std::cout << "Now you must go to the southern entrance and go into a long corridor.";
	page = 106;
	return page;
}

//page 111
int Room11()
{
	bool done = false;
	int choice = -1;
	int door = HP_SIMPLE_WOODEN_DOOR;
	int monsterHP = HP_DIRE_RAT;
	mp += 10 * intel;
	hp += 15 * con;
	int enemyNumber = 2;

	std::cout << "" << std::endl;
	std::cout << "You decided to go to the southern entrance." << std::endl;
	std::cout << "The room has two dire rats! Kill them all!" << std::endl;
	std::cout << "" << std::endl;

	//shows the health and mana status
	std::cout << "Your HP is " << hp << " points" << std::endl;
	std::cout << "Your MP is " << mp << " points" << std::endl;
	std::cout << "" << std::endl;
	
	//call a function that hits monsters
	hittingMonsters(choice, monsterHP, "dire rat", enemyNumber);
	std::cout << "Now you must go to the northern entrance.";
	page = 107;
	return page;
}

//page 112
int Room12()
{
	bool done = false;
	int choice = -1;
	int monsterHP = HP_MONSTROUS_SPIDER;
	mp += 10 * intel;
	hp += 15 * con;

	std::cout << "" << std::endl;
	std::cout << "You decided to go to the northern entrance." << std::endl;
	std::cout << "The room has a monstrous spider, and you must defeat it!" << std::endl;
	std::cout << "" << std::endl;

	//shows the health and mana status
	std::cout << "Your HP is " << hp << " points" << std::endl;
	std::cout << "Your MP is " << mp << " points" << std::endl;
	std::cout << "" << std::endl;

	//call a function to hit a monster
	hittingMonster(choice, monsterHP, "monstrous spider");

	do
	{
		//give player choices
		std::cout << "Now you need to decide whether to go to the western (1) or southern entrance (2): ";
		std::cin >> page;

		//validate player input
		if (page == 1)
		{
			page = 116;
			done = true;
		}
		else
		{
			if (page == 2)
			{
				page = 113;
				done = true;
			}
			else
			{
				std::cout << "You need to choose option 1 or 2." << std::endl;
				std::cout << "" << std::endl;
			}
		}
	} while (!done);
	return page;
}

//page 113
int Room13()
{
	bool done = false;
	int choice = -1;
	int monsterHP = HP_WARRIOR_SVIRFNEBLIN;
	mp += 10 * intel;
	hp += 15 * con;

	std::cout << "" << std::endl;
	std::cout << "You've reached the north entrance room." << std::endl;
	std::cout << "Someone has scrawled a demonic face on the west wall, and iron chains hang from the ceiling" << std::endl;
	std::cout << "in the north-west corner of the room." << std::endl;
	std::cout << "The room has a warrior Svirfneblin! You must defeat him!" << std::endl;

	std::cout << "" << std::endl;

	//shows the health and mana status
	std::cout << "Your HP is " << hp << " points" << std::endl;
	std::cout << "Your MP is " << mp << " points" << std::endl;
	std::cout << "" << std::endl;

	//call a function to hit a monster
	hittingMonster(choice, monsterHP, "warrior Svirfneblin");
	std::cout << "Now you must run to the southern entrance!";
	page = 117;
	return page;
}

//page 114
int Room14()
{
	std::cout << "           IT'S A TRAP!!!!" << std::endl;
	std::cout << "In this room you fell into a trap!!!" << std::endl;
	system("pause");
	int page = -2;
	return page;
}

//page 115
int Room15()
{
	bool done = false;
	int choice = -1;
	int door = HP_SIMPLE_WOODEN_DOOR;
	int monsterHP = HP_SPIDER_SWARM;
	mp += 10 * intel;
	hp += 15 * con;

	std::cout << "" << std::endl;
	std::cout << "You've reached the southern entrance room." << std::endl;
	std::cout << "The room has a spider swarm!" << std::endl;
	std::cout << "You must attack!" << std::endl;
	std::cout << "" << std::endl;

	//shows the health and mana status
	std::cout << "Your HP is " << hp << " points" << std::endl;
	std::cout << "Your MP is " << mp << " points" << std::endl;
	std::cout << "" << std::endl;

	//call a function to hit a monster
	hittingMonster(choice, monsterHP, "spider swarm");
	std::cout << "Now you must run to the northern entrance.";
	page = 117;
	return page;
}

//page 116
int Room16()
{
	bool done = false;
	int choice = -1;
	int page = -1;
	int door = HP_GOOD_WOODEN_DOOR;
	mp += 10 * intel;
	hp += 15 * con;

	std::cout << "" << std::endl;
	std::cout << "You decided to go to the northern entrance." << std::endl;
	std::cout << "The room is empty with a bad smell of blood." << std::endl;
	std::cout << "There is a stuck good wooden door located on the southern entrance." << std::endl;
	std::cout << "You must break it!" << std::endl;
	std::cout << "" << std::endl;

	//shows the health and mana status
	std::cout << "Your HP is " << hp << " points" << std::endl;
	std::cout << "Your MP is " << mp << " points" << std::endl;
	std::cout << "" << std::endl;
	
	//call a function to hit the door
	door = hittingDoors(choice, door);
	std::cout << "Now you must run to the southen entrance.";
	page = 108;
	return page;
}

