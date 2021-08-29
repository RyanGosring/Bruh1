/* Copyright (C) 2009 - 2010 ScriptDevZero <http://github.com/scriptdevzero/scriptdevzero>
* This program is free software; you can redistribute it and/or modify
* it under the terms of the GNU General Public License as published by
* the Free Software Foundation; either version 2 of the License, or
* (at your option) any later version.
*
* This program is distributed in the hope that it will be useful,
* but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
* GNU General Public License for more details.
*
* You should have received a copy of the GNU General Public License
* along with this program; if not, write to the Free Software
* Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
*/

#include "scriptPCH.h"
#include "custom.h"
#include "ScriptedAI.h"
#include <ctime>

#if defined(_MSC_VER) && (_MSC_VER >= 1900)    
# pragma execution_character_set("utf-8")    
#endif

// TELEPORT NPC

bool GossipHello_TeleportNPC(Player* player, Creature* _Creature)
{
	//char* tmp = new char[100];
	//sprintf(tmp, "|cFF0041FF�ҵ��ʻ����֣�[%d]��|r ��", player->Getjifen());
	//player->ADD_GOSSIP_ITEM(4, tmp, GOSSIP_SENDER_MAIN, 0);

	//std::cout << player->Getjifen() << std::endl;

	// HORDE
	if (player->GetTeam() == HORDE)
	{
		// player->ADD_GOSSIP_ITEM(5, "PreTBC Mall"          , GOSSIP_SENDER_MAIN, 74);
		player->ADD_GOSSIP_ITEM(5, "���Ǵ���", GOSSIP_SENDER_MAIN, 1);
		player->ADD_GOSSIP_ITEM(5, "��ʼ֮��", GOSSIP_SENDER_MAIN, 3);
		player->ADD_GOSSIP_ITEM(5, "���˸���", GOSSIP_SENDER_MAIN, 5);
		player->ADD_GOSSIP_ITEM(5, "�ŶӸ���", GOSSIP_SENDER_MAIN, 101);
		player->ADD_GOSSIP_ITEM(5, "ս���ٻ�", GOSSIP_SENDER_MAIN, 10);
		player->ADD_GOSSIP_ITEM(5, "Ұ��BOSS", GOSSIP_SENDER_MAIN, 6000);
		player->ADD_GOSSIP_ITEM(5, "����ķ��", GOSSIP_SENDER_MAIN, 6010);
		player->ADD_GOSSIP_ITEM(5, "��������", GOSSIP_SENDER_MAIN, 6020);
		player->ADD_GOSSIP_ITEM(5, "�������", GOSSIP_SENDER_MAIN, 6030);

		player->SEND_GOSSIP_MENU(DEFAULT_GOSSIP_MESSAGE, _Creature->GetGUID());
	}
	// ALLIANCE
	else
	{
		//player->ADD_GOSSIP_ITEM(5, "PreTBC Mall" , GOSSIP_SENDER_MAIN, 74);
		player->ADD_GOSSIP_ITEM(5, "���Ǵ���.", GOSSIP_SENDER_MAIN, 2);
		player->ADD_GOSSIP_ITEM(5, "��ʼ֮��", GOSSIP_SENDER_MAIN, 4);
		player->ADD_GOSSIP_ITEM(5, "���˸���", GOSSIP_SENDER_MAIN, 5);
		player->ADD_GOSSIP_ITEM(5, "�ŶӸ���", GOSSIP_SENDER_MAIN, 101);
		player->ADD_GOSSIP_ITEM(5, "ս���ٻ�", GOSSIP_SENDER_MAIN, 11);
		player->ADD_GOSSIP_ITEM(5, "Ұ��BOSS", GOSSIP_SENDER_MAIN, 6000);
		player->ADD_GOSSIP_ITEM(5, "����ķ��", GOSSIP_SENDER_MAIN, 6010);
		player->ADD_GOSSIP_ITEM(5, "��������", GOSSIP_SENDER_MAIN, 6020);
		player->ADD_GOSSIP_ITEM(5, "�������", GOSSIP_SENDER_MAIN, 6030);

		player->SEND_GOSSIP_MENU(DEFAULT_GOSSIP_MESSAGE, _Creature->GetGUID());
	}
	return true;
}

void SendDefaultMenu_TeleportNPC(Player* player, Creature* _Creature, uint32 action)
{
	switch (action)
	{
	case 1: // Cities [HORDE]
		player->ADD_GOSSIP_ITEM(5, "�¸�����", GOSSIP_SENDER_MAIN, 20);
		player->ADD_GOSSIP_ITEM(5, "�İ���", GOSSIP_SENDER_MAIN, 21);
		player->ADD_GOSSIP_ITEM(5, "������", GOSSIP_SENDER_MAIN, 22);
		player->ADD_GOSSIP_ITEM(5, "�ӻ�ɭ", GOSSIP_SENDER_MAIN, 609);
		//player->ADD_GOSSIP_ITEM(5, "Goldshire (Stormwind)" , GOSSIP_SENDER_MAIN, 4018);
		player->ADD_GOSSIP_ITEM(5, "<-[���˵�]", GOSSIP_SENDER_MAIN, 100);

		player->SEND_GOSSIP_MENU(DEFAULT_GOSSIP_MESSAGE, _Creature->GetGUID());
		break;
	case 2: // Cities [ALLIANCE]
		player->ADD_GOSSIP_ITEM(5, "�����", GOSSIP_SENDER_MAIN, 23);
		player->ADD_GOSSIP_ITEM(5, "��¯��", GOSSIP_SENDER_MAIN, 24);
		player->ADD_GOSSIP_ITEM(5, "������˹", GOSSIP_SENDER_MAIN, 25);
		player->ADD_GOSSIP_ITEM(5, "�ӻ�ɭ", GOSSIP_SENDER_MAIN, 609);
		//player->ADD_GOSSIP_ITEM(5, "Razor Hill(Orgrimmar)" , GOSSIP_SENDER_MAIN, 4017);
		player->ADD_GOSSIP_ITEM(5, "<-[���˵�]", GOSSIP_SENDER_MAIN, 100);

		player->SEND_GOSSIP_MENU(DEFAULT_GOSSIP_MESSAGE, _Creature->GetGUID());
		break;
	case 3: // Starting Places [HORDE]
		player->ADD_GOSSIP_ITEM(5, "��ӰĹѨ", GOSSIP_SENDER_MAIN, 40);
		player->ADD_GOSSIP_ITEM(5, "������", GOSSIP_SENDER_MAIN, 41);
		player->ADD_GOSSIP_ITEM(5, "������Ӫ��", GOSSIP_SENDER_MAIN, 42);
		player->ADD_GOSSIP_ITEM(5, "<-[���˵�]", GOSSIP_SENDER_MAIN, 100);

		player->SEND_GOSSIP_MENU(DEFAULT_GOSSIP_MESSAGE, _Creature->GetGUID());
		break;
	case 4: // Starting Places [ALLIANCE]
		player->ADD_GOSSIP_ITEM(5, "����ɽ��", GOSSIP_SENDER_MAIN, 43);
		player->ADD_GOSSIP_ITEM(5, "����ɽ��", GOSSIP_SENDER_MAIN, 44);
		player->ADD_GOSSIP_ITEM(5, "��Ӱ��", GOSSIP_SENDER_MAIN, 45);
		player->ADD_GOSSIP_ITEM(5, "<-[���˵�]", GOSSIP_SENDER_MAIN, 100);

		player->SEND_GOSSIP_MENU(DEFAULT_GOSSIP_MESSAGE, _Creature->GetGUID());
		break;
	case 10: // ����ս��
		player->ADD_GOSSIP_ITEM(5, "ս��Ͽ��", GOSSIP_SENDER_MAIN, 140);
		player->ADD_GOSSIP_ITEM(5, "����ϣ���", GOSSIP_SENDER_MAIN, 141);
		player->ADD_GOSSIP_ITEM(5, "��������ɽ��", GOSSIP_SENDER_MAIN, 142);
		player->ADD_GOSSIP_ITEM(5, "������ʲ������", GOSSIP_SENDER_MAIN, 4015);
		player->ADD_GOSSIP_ITEM(5, "<-[���˵�]", GOSSIP_SENDER_MAIN, 100);

		player->SEND_GOSSIP_MENU(DEFAULT_GOSSIP_MESSAGE, _Creature->GetGUID());
		break;
	case 11: // ����ս��
		player->ADD_GOSSIP_ITEM(5, "ս��Ͽ��", GOSSIP_SENDER_MAIN, 143);
		player->ADD_GOSSIP_ITEM(5, "����ϣ���", GOSSIP_SENDER_MAIN, 144);
		player->ADD_GOSSIP_ITEM(5, "��������ɽ��", GOSSIP_SENDER_MAIN, 145);
		player->ADD_GOSSIP_ITEM(5, "������ʲ������", GOSSIP_SENDER_MAIN, 4015);
		player->ADD_GOSSIP_ITEM(5, "<-[���˵�]", GOSSIP_SENDER_MAIN, 100);

		player->SEND_GOSSIP_MENU(DEFAULT_GOSSIP_MESSAGE, _Creature->GetGUID());
		break;
	case 5: // Instances [PAGE 1]
		player->ADD_GOSSIP_ITEM(5, "������Ѩ", GOSSIP_SENDER_MAIN, 1249);
		player->ADD_GOSSIP_ITEM(5, "������", GOSSIP_SENDER_MAIN, 1250);
		player->ADD_GOSSIP_ITEM(5, "Ӱ���Ǳ�", GOSSIP_SENDER_MAIN, 1251);
		player->ADD_GOSSIP_ITEM(5, "�������", GOSSIP_SENDER_MAIN, 1267);
		player->ADD_GOSSIP_ITEM(5, "ŭ���ѹ�", GOSSIP_SENDER_MAIN, 1269);
		player->ADD_GOSSIP_ITEM(5, "�ڰ���Ԩ", GOSSIP_SENDER_MAIN, 1252);
		player->ADD_GOSSIP_ITEM(5, "�굶����", GOSSIP_SENDER_MAIN, 1254);
		player->ADD_GOSSIP_ITEM(5, "�굶�ߵ�", GOSSIP_SENDER_MAIN, 1256);
		player->ADD_GOSSIP_ITEM(5, "Ѫɫ�޵�Ժ", GOSSIP_SENDER_MAIN, 1257);
		player->ADD_GOSSIP_ITEM(7, "[��һҳ]->", GOSSIP_SENDER_MAIN, 5551);
		player->ADD_GOSSIP_ITEM(5, "<-[���˵�]", GOSSIP_SENDER_MAIN, 100);

		player->SEND_GOSSIP_MENU(DEFAULT_GOSSIP_MESSAGE, _Creature->GetGUID());
		break;
	case 5551: // Instances [PAGE 2]
		player->ADD_GOSSIP_ITEM(5, "ŵĪ���", GOSSIP_SENDER_MAIN, 1268);
		player->ADD_GOSSIP_ITEM(5, "�´���", GOSSIP_SENDER_MAIN, 1258);
		player->ADD_GOSSIP_ITEM(5, "���������", GOSSIP_SENDER_MAIN, 1259);
		player->ADD_GOSSIP_ITEM(5, "������", GOSSIP_SENDER_MAIN, 1260);
		player->ADD_GOSSIP_ITEM(5, "������������", GOSSIP_SENDER_MAIN, 1261);
		player->ADD_GOSSIP_ITEM(5, "��ʯ��Ԩ", GOSSIP_SENDER_MAIN, 1262);
		player->ADD_GOSSIP_ITEM(5, "����֮�", GOSSIP_SENDER_MAIN, 1263);
		player->ADD_GOSSIP_ITEM(5, "��ʯ��", GOSSIP_SENDER_MAIN, 1264);
		player->ADD_GOSSIP_ITEM(5, "˹̹��ķ", GOSSIP_SENDER_MAIN, 1265);
		player->ADD_GOSSIP_ITEM(5, "ͨ��ѧԺ", GOSSIP_SENDER_MAIN, 1266);
		player->ADD_GOSSIP_ITEM(7, "<-[��һҳ]", GOSSIP_SENDER_MAIN, 5);
		player->ADD_GOSSIP_ITEM(5, "<-[���˵�]", GOSSIP_SENDER_MAIN, 100);

		player->SEND_GOSSIP_MENU(DEFAULT_GOSSIP_MESSAGE, _Creature->GetGUID());
		break;
	case 101: // Raids
		player->ADD_GOSSIP_ITEM(5, "���������", GOSSIP_SENDER_MAIN, 4000);
		player->ADD_GOSSIP_ITEM(5, "���ݿ�ϣ�ǵĳ�Ѩ", GOSSIP_SENDER_MAIN, 4001);
		player->ADD_GOSSIP_ITEM(5, "�ۻ�֮��", GOSSIP_SENDER_MAIN, 4002);
		player->ADD_GOSSIP_ITEM(5, "����Ѩ", GOSSIP_SENDER_MAIN, 4003);
		player->ADD_GOSSIP_ITEM(5, "����������", GOSSIP_SENDER_MAIN, 4004);
		player->ADD_GOSSIP_ITEM(5, "����������", GOSSIP_SENDER_MAIN, 4005);
		player->ADD_GOSSIP_ITEM(5, "�ɿ�����˹", GOSSIP_SENDER_MAIN, 4006);
		player->ADD_GOSSIP_ITEM(5, "������Ѩ", GOSSIP_SENDER_MAIN, 4007);
		player->ADD_GOSSIP_ITEM(5, "<-[���˵�]", GOSSIP_SENDER_MAIN, 100);

		player->SEND_GOSSIP_MENU(DEFAULT_GOSSIP_MESSAGE, _Creature->GetGUID());
		break;
	case 6000: // boss
		player->ADD_GOSSIP_ITEM(5, "ĺɫɭ��-��Ī��˿", GOSSIP_SENDER_MAIN, 5000);
		player->ADD_GOSSIP_ITEM(5, "������-��������", GOSSIP_SENDER_MAIN, 5001);
		player->ADD_GOSSIP_ITEM(5, "�ҹ�-̩����", GOSSIP_SENDER_MAIN, 5002);
		player->ADD_GOSSIP_ITEM(5, "�������������׸�˹", GOSSIP_SENDER_MAIN, 5003);
		player->ADD_GOSSIP_ITEM(5, "����˹-������", GOSSIP_SENDER_MAIN, 5004);
		player->ADD_GOSSIP_ITEM(5, "����֮��-������", GOSSIP_SENDER_MAIN, 5005);
		player->ADD_GOSSIP_ITEM(5, "ϣ����˹-��Ԫ��", GOSSIP_SENDER_MAIN, 5006);
		player->ADD_GOSSIP_ITEM(5, "<-[���˵�]", GOSSIP_SENDER_MAIN, 100);

		player->SEND_GOSSIP_MENU(DEFAULT_GOSSIP_MESSAGE, _Creature->GetGUID());
		break;
	case 6010: // Kalimdor [PAGE 1]
		player->ADD_GOSSIP_ITEM(5, "�ҹ�", GOSSIP_SENDER_MAIN, 601);
		player->ADD_GOSSIP_ITEM(5, "�ں���", GOSSIP_SENDER_MAIN, 602);
		player->ADD_GOSSIP_ITEM(5, "����֮��", GOSSIP_SENDER_MAIN, 603);
		player->ADD_GOSSIP_ITEM(5, "��¡����", GOSSIP_SENDER_MAIN, 604);
		player->ADD_GOSSIP_ITEM(5, "��������", GOSSIP_SENDER_MAIN, 605);
		player->ADD_GOSSIP_ITEM(5, "����˹", GOSSIP_SENDER_MAIN, 606);
		player->ADD_GOSSIP_ITEM(5, "ϣ����˹", GOSSIP_SENDER_MAIN, 607);
		player->ADD_GOSSIP_ITEM(5, "ʯצɽ��", GOSSIP_SENDER_MAIN, 608);
		player->ADD_GOSSIP_ITEM(5, "������˹", GOSSIP_SENDER_MAIN, 609);
		player->ADD_GOSSIP_ITEM(5, "ƶ�֮��", GOSSIP_SENDER_MAIN, 610);
		player->ADD_GOSSIP_ITEM(5, "ǧ��ʯ��", GOSSIP_SENDER_MAIN, 611);
		player->ADD_GOSSIP_ITEM(5, "������", GOSSIP_SENDER_MAIN, 612);
		player->ADD_GOSSIP_ITEM(7, "[��һҳ]->", GOSSIP_SENDER_MAIN, 6011);
		player->ADD_GOSSIP_ITEM(5, "<-[���˵�]", GOSSIP_SENDER_MAIN, 100);

		player->SEND_GOSSIP_MENU(DEFAULT_GOSSIP_MESSAGE, _Creature->GetGUID());
		break;
	case 6011: // Kalimdor [PAGE 2]
		player->ADD_GOSSIP_ITEM(5, "���ݳ�", GOSSIP_SENDER_MAIN, 628);
		player->ADD_GOSSIP_ITEM(5, "������", GOSSIP_SENDER_MAIN, 631);
		player->ADD_GOSSIP_ITEM(5, "�����ӻ���ɽ", GOSSIP_SENDER_MAIN, 632);
		player->ADD_GOSSIP_ITEM(7, "<-[��һҳ]", GOSSIP_SENDER_MAIN, 6010);
		player->ADD_GOSSIP_ITEM(5, "<-[���˵�]", GOSSIP_SENDER_MAIN, 100);

		player->SEND_GOSSIP_MENU(DEFAULT_GOSSIP_MESSAGE, _Creature->GetGUID());
		break;
	case 6020: // Eastern Kingdoms [PAGE 1]
		player->ADD_GOSSIP_ITEM(5, "����ϣ�ߵ�", GOSSIP_SENDER_MAIN, 613);
		player->ADD_GOSSIP_ITEM(5, "����֮��", GOSSIP_SENDER_MAIN, 614);
		player->ADD_GOSSIP_ITEM(5, "��Ī��", GOSSIP_SENDER_MAIN, 615);
		player->ADD_GOSSIP_ITEM(5, "ĺɫɭ��", GOSSIP_SENDER_MAIN, 616);
		player->ADD_GOSSIP_ITEM(5, "������֮��", GOSSIP_SENDER_MAIN, 617);
		player->ADD_GOSSIP_ITEM(5, "������", GOSSIP_SENDER_MAIN, 618);
		player->ADD_GOSSIP_ITEM(5, "ϣ��˹����������", GOSSIP_SENDER_MAIN, 619);
		player->ADD_GOSSIP_ITEM(5, "�༹ɽ", GOSSIP_SENDER_MAIN, 620);
		player->ADD_GOSSIP_ITEM(5, "����ɭ��", GOSSIP_SENDER_MAIN, 621);
		player->ADD_GOSSIP_ITEM(5, "������/���", GOSSIP_SENDER_MAIN, 622);
		player->ADD_GOSSIP_ITEM(5, "��������", GOSSIP_SENDER_MAIN, 623);
		player->ADD_GOSSIP_ITEM(5, "������", GOSSIP_SENDER_MAIN, 624);
		player->ADD_GOSSIP_ITEM(5, "����˹���ֵ�", GOSSIP_SENDER_MAIN, 625);
		player->ADD_GOSSIP_ITEM(7, "[��һҳ]->", GOSSIP_SENDER_MAIN, 6021);
		player->ADD_GOSSIP_ITEM(5, "<-[���˵�]", GOSSIP_SENDER_MAIN, 100);

		player->SEND_GOSSIP_MENU(DEFAULT_GOSSIP_MESSAGE, _Creature->GetGUID());
		break;
	case 6021: // �������� [PAGE 2]
		player->ADD_GOSSIP_ITEM(5, "�ڱ���", GOSSIP_SENDER_MAIN, 626);
		player->ADD_GOSSIP_ITEM(5, "ʪ��", GOSSIP_SENDER_MAIN, 627);
		player->ADD_GOSSIP_ITEM(5, "�ر�����", GOSSIP_SENDER_MAIN, 629);
		player->ADD_GOSSIP_ITEM(5, "���ȷ�ľ��", GOSSIP_SENDER_MAIN, 630);
		player->ADD_GOSSIP_ITEM(7, "<-[��һҳ]", GOSSIP_SENDER_MAIN, 6020);
		player->ADD_GOSSIP_ITEM(5, "<-[���˵�]", GOSSIP_SENDER_MAIN, 100);

		player->SEND_GOSSIP_MENU(DEFAULT_GOSSIP_MESSAGE, _Creature->GetGUID());
		break;
	case 6030: // �۹��
		player->ADD_GOSSIP_ITEM(5, "�����޸�������", GOSSIP_SENDER_MAIN, 700);
		player->ADD_GOSSIP_ITEM(5, "ǧ��ʯ����߷�", GOSSIP_SENDER_MAIN, 701);
		player->ADD_GOSSIP_ITEM(5, "��������ˮ���", GOSSIP_SENDER_MAIN, 702);
		player->ADD_GOSSIP_ITEM(5, "��¯����ɽɽ��", GOSSIP_SENDER_MAIN, 703);
		player->ADD_GOSSIP_ITEM(5, "���Ӷ�ɽ�۹��", GOSSIP_SENDER_MAIN, 704);
		player->ADD_GOSSIP_ITEM(5, "���Ϻ���û�й�", GOSSIP_SENDER_MAIN, 705);
		//player->ADD_GOSSIP_ITEM(5, "���ɭ��һƬ��", GOSSIP_SENDER_MAIN, 706);
		player->ADD_GOSSIP_ITEM(5, "��˵�е� GM ��", GOSSIP_SENDER_MAIN, 707);
		player->ADD_GOSSIP_ITEM(5, "<-[���˵�]", GOSSIP_SENDER_MAIN, 100);

		player->SEND_GOSSIP_MENU(DEFAULT_GOSSIP_MESSAGE, _Creature->GetGUID());
		break;


		// ----### CITIES ###----

		// ### HORDE ###

	case 20: // �¸�����
		player->CLOSE_GOSSIP_MENU();
		player->TeleportTo(1, 1601.08f, -4378.69f, 9.9846f, 2.14362f);
		break;
	case 21: // �İ���
		player->CLOSE_GOSSIP_MENU();
		player->TeleportTo(0, 1633.75f, 240.167f, -43.1034f, 6.26128f);
		break;
	case 22: // ������
		player->CLOSE_GOSSIP_MENU();
		player->TeleportTo(1, -1274.45f, 71.8601f, 128.159f, 2.80623f);
		break;

		// ### ALLIANCE ###

	case 23: // �����
		player->CLOSE_GOSSIP_MENU();
		player->TeleportTo(0, -8842.09f, 626.358f, 94.0867f, 3.61363f);
		break;
	case 24: // ��¯��
		player->CLOSE_GOSSIP_MENU();
		player->TeleportTo(0, -4900.47f, -962.585f, 501.455f, 5.40538f);
		break;
	case 25: // ������˹
		player->CLOSE_GOSSIP_MENU();
		player->TeleportTo(1, 9869.91f, 2493.58f, 1315.88f, 2.78897f);
		break;

		// ----### STARTING PLACES ####----

		// ### HORDE ###
	case 40: // Shadow Grave
		player->CLOSE_GOSSIP_MENU();
		player->TeleportTo(0, 1663.517f, 1678.187744f, 120.5303f, 0.0f);
		break;
	case 41: // Valley of Trials
		player->CLOSE_GOSSIP_MENU();
		player->TeleportTo(1, -602.1253f, -4262.4208f, 38.956341f, 0.0f);
		break;
	case 42: // Camp Narache
		player->CLOSE_GOSSIP_MENU();
		player->TeleportTo(1, -2914.16992f, -266.061798f, 53.658211f, 0.0f);
		break;

		// ### ALLIANCE ###

	case 43: // Nortshire Valley
		player->CLOSE_GOSSIP_MENU();
		player->TeleportTo(0, -8943.133789f, -132.934921f, 83.704269f, 0.0f);
		break;
	case 44: // Coldridge Valley
		player->CLOSE_GOSSIP_MENU();
		player->TeleportTo(0, -6231.106445f, 332.270477f, 383.153931f, 0.0f);
		break;
	case 45: // Shadowglen
		player->CLOSE_GOSSIP_MENU();
		player->TeleportTo(1, 10329.918945f, 833.500305f, 1326.260620f, 0.0f);
		break;

		// ### ����ս�� ###
	case 140: // ս��Ͽ��
		player->CLOSE_GOSSIP_MENU();
		player->TeleportTo(1, 1036.7948f, -2106.138672f, 122.9455f, 0.0f);
		break;
	case 141: // ����ϣ���
		player->CLOSE_GOSSIP_MENU();
		player->TeleportTo(0, -847.9535f, -3519.7649f, 72.6077f, 0.0f);
		break;
	case 142: // ��������ɽ��
		player->CLOSE_GOSSIP_MENU();
		player->TeleportTo(0, 392.4830f, -977.0000f, 110.07300f, 0.0f);
		break;

		// ### ����ս�� ###

	case 143: // ս��Ͽ��
		player->CLOSE_GOSSIP_MENU();
		player->TeleportTo(1, 1499.630005f, -1845.650024f, 126.347000f, 0.0f);
		break;
	case 144: // ����ϣ���
		player->CLOSE_GOSSIP_MENU();
		player->TeleportTo(0, -1222.6291f, -2530.4226f, 22.3720f, 0.0f);
		break;
	case 145: // ��������ɽ��
		player->CLOSE_GOSSIP_MENU();
		player->TeleportTo(0, -8.4808f, -327.7529f, 131.1703f, 0.0f);
		break;

		// ----### INSTANCES ###----

	case 50: // Dire Maul
		player->CLOSE_GOSSIP_MENU();
		player->TeleportTo(1, -3762.340820f, 1216.537598f, 127.434608f, 0.0f);
		break;
	case 51: // Blackrock Spire
		player->CLOSE_GOSSIP_MENU();
		player->TeleportTo(0, -7528.554688f, -1222.907227f, 285.732941f, 0.0f);
		break;
	case 52: // Zul'Gurub
		player->CLOSE_GOSSIP_MENU();
		player->TeleportTo(0, -11916.179688f, -1190.977051f, 85.137901f, 0.0f);
		break;
	case 53: // Onyxia's Lair
		player->CLOSE_GOSSIP_MENU();
		player->TeleportTo(1, -4682.391602f, -3709.857422f, 46.792862f, 0.0f);
		break;
	case 54: // Searing Gorge (Moltencore, Blackwinglair)
		player->CLOSE_GOSSIP_MENU();
		player->TeleportTo(0, -7342.270020f, -1096.863892f, 277.06930f, 0.0f);
		break;
	case 55: // �ɿ�����˹
		player->CLOSE_GOSSIP_MENU();
		player->TeleportTo(0, 3121.061768f, -3689.973389f, 133.458786f, 0.0f);
		break;
	case 56: // Stratholme Backdoor Entrance
		player->CLOSE_GOSSIP_MENU();
		player->TeleportTo(0, 3160.416992f, -4038.750244f, 104.177376f, 0.0f);
		break;
	case 57: // Stratholme Main Entrance
		player->CLOSE_GOSSIP_MENU();
		player->TeleportTo(0, 3357.214355f, -3379.713135f, 144.780853f, 0.0f);
		break;
	case 58: // Scholomance
		player->CLOSE_GOSSIP_MENU();
		player->TeleportTo(0, 1252.319824f, -2587.151123f, 92.886772f, 0.0f);
		break;

		// ---### ZONES ###---

	case 70: // Silithus
		player->CLOSE_GOSSIP_MENU();
		player->TeleportTo(1, -7430.070313f, 1002.554565f, 1.249787f, 0.0f);
		break;
	case 71: // Durotar
		player->CLOSE_GOSSIP_MENU();
		player->TeleportTo(1, 1006.426819f, -4439.258789f, 11.352882f, 0.0f);
		break;
	case 72: // Ashenvale
		player->CLOSE_GOSSIP_MENU();
		player->TeleportTo(1, 1922.842651f, -2169.429688f, 94.327400f, 0.0f);
		break;
	case 73: // Tanaris
		player->CLOSE_GOSSIP_MENU();
		player->TeleportTo(1, -7180.401367f, -3773.328369f, 8.728320f, 0.0f);
		break;
	case 74: // Pretbc Mall
			 //player->CLOSE_GOSSIP_MENU();
			 //player->TeleportTo(1, 16201.107422f, 16205.1875f, 0.140072f, 1.630427f);
		break;
	case 4015:// ������ʲ������
		player->CLOSE_GOSSIP_MENU();
		player->TeleportTo(0, -13261.3f, 168.294f, 35.0792f, 1.00688f);
		break;
	case 4017:// Razor Hill
		player->CLOSE_GOSSIP_MENU();
		player->TeleportTo(1, 315.721f, -4743.4f, 10.4867f, 0.0f);
		break;
	case 4018:// Goldshire
		player->CLOSE_GOSSIP_MENU();
		player->TeleportTo(0, -9464.0f, 62.0f, 56.0f, 0.0f);
		break;
	case 1249://teleport player to the Wailing Caverns
		player->CLOSE_GOSSIP_MENU();
		player->TeleportTo(1, -722.53f, -2226.30f, 16.94f, 2.71f);
		break;
	case 1250://teleport player to the Deadmines
		player->CLOSE_GOSSIP_MENU();
		player->TeleportTo(0, -11212.04f, 1658.58f, 25.67f, 1.45f);
		break;
	case 1251://teleport player to Shadowfang Keep
		player->CLOSE_GOSSIP_MENU();
		player->TeleportTo(0, -254.47f, 1524.68f, 76.89f, 1.56f);
		break;
	case 1252://teleport player to Blackfathom Deeps
		player->CLOSE_GOSSIP_MENU();
		player->TeleportTo(1, 4254.58f, 664.74f, -29.04f, 1.97f);
		break;
	case 1254://teleport player to Razorfen Kraul
		player->CLOSE_GOSSIP_MENU();
		player->TeleportTo(1, -4484.04f, -1739.40f, 86.47f, 1.23f);
		break;
	case 1256://teleport player to Razorfen Downs
		player->CLOSE_GOSSIP_MENU();
		player->TeleportTo(1, -4645.08f, -2470.85f, 85.53f, 4.39f);
		break;
	case 1257://teleport player to the Scarlet Monastery
		player->CLOSE_GOSSIP_MENU();
		player->TeleportTo(0, 2843.89f, -693.74f, 139.32f, 5.11f);
		break;
	case 1258://teleport player to Uldaman
		player->CLOSE_GOSSIP_MENU();
		player->TeleportTo(0, -6119.70f, -2957.30f, 204.11f, 0.03f);
		break;
	case 1259://teleport player to Zul'Farrak
		player->CLOSE_GOSSIP_MENU();
		player->TeleportTo(1, -6839.39f, -2911.03f, 8.87f, 0.41f);
		break;
	case 1260://teleport player to Maraudon
		player->CLOSE_GOSSIP_MENU();
		player->TeleportTo(1, -1433.33f, 2955.34f, 96.21f, 4.82f);
		break;
	case 1261://teleport player to the Sunken Temple
		player->CLOSE_GOSSIP_MENU();
		player->TeleportTo(109, -319.2399f, 99.900f, -131.850f, 0.00f);
		break;
	case 1262://teleport player to Blackrock Depths
		player->CLOSE_GOSSIP_MENU();
		player->TeleportTo(0, -7301.03f, -913.19f, 165.37f, 0.08f);
		break;
	case 1263://teleport player to Dire Maul
		player->CLOSE_GOSSIP_MENU();
		player->TeleportTo(1, -3982.47f, 1127.79f, 161.02f, 0.05f);
		break;
	case 1264://teleport player to Blackrock Spire
		player->CLOSE_GOSSIP_MENU();
		player->TeleportTo(0, -7535.43f, -1212.04f, 285.45f, 5.29f);
		break;
	case 1265://teleport player to Stratholme
		player->CLOSE_GOSSIP_MENU();
		player->TeleportTo(0, 3263.54f, -3379.46f, 143.59f, 0.00f);
		break;
	case 1266://teleport player to Scholomance
		player->CLOSE_GOSSIP_MENU();
		player->TeleportTo(0, 1219.01f, -2604.66f, 85.61f, 0.50f);
		break;
	case 1267://teleport player to ����Ǽ���
		player->CLOSE_GOSSIP_MENU();
		player->TeleportTo(34, 54.23f, 0.28f, -18.02f, 0.00f);
		break;
	case 1268://teleport player to ŵĪ���
		player->CLOSE_GOSSIP_MENU();
		player->TeleportTo(90, -332.03f, -2.20f, -151.01f, 0.00f);
		break;
	case 1269://teleport player to ŭ���ѹ�
		player->CLOSE_GOSSIP_MENU();
		player->TeleportTo(389, 3.800f, -14.80f, -17.00f, 0.00f);
		break;
	case 4000:// Teleport to Zul'Gurub
		player->CLOSE_GOSSIP_MENU();		
		player->TeleportTo(0, -11916.7f, -1212.82f, 92.2868f, 4.6095f);
		break;
	case 4001:// Teleport to Onyxia's Lair
		player->CLOSE_GOSSIP_MENU();
		player->TeleportTo(1, -4707.44f, -3726.82f, 54.6723f, 3.8f);
		break;
	case 4002:// Teleport to Molten Core
		player->CLOSE_GOSSIP_MENU();
		player->TeleportTo(230, 1121.451172f, -454.316772f, -101.329536f, 3.5f);
		break;
	case 4003:// Teleport to Blackwing Lair
		player->CLOSE_GOSSIP_MENU();
		player->TeleportTo(469, -7665.55f, -1102.49f, 400.679f, 0.0f);
		break;
	case 4004:// Ruins of Ahn'Qiraj
		player->CLOSE_GOSSIP_MENU();
		player->TeleportTo(1, -8409.032227f, 1498.830933f, 27.361542f, 2.497567f);
		break;
	case 4005:// Temple of Ahn'Qiraj
		player->CLOSE_GOSSIP_MENU();
		player->TeleportTo(1, -8245.837891f, 1983.736206f, 129.071686f, 0.936195f);
		break;
	case 4006:// Naxxramas
		player->CLOSE_GOSSIP_MENU();
		player->TeleportTo(533, 3005.87f, -3435.0f, 293.89f, 0.0f);
		break;
	case 4007://teleport player to ������Ѩ 
		player->CLOSE_GOSSIP_MENU();
		player->TeleportTo(553, 3521.30f, -5237.5600f, 137.72f, 0.00f);
		break;
	case 601: // Kalimdor -> Ashenvale
		player->CLOSE_GOSSIP_MENU();
		player->TeleportTo(1, 3469.43f, 847.62f, 6.36476f, 0.0f);
		break;
	case 602: // Kalimdor -> �ں���
		player->CLOSE_GOSSIP_MENU();
		player->TeleportTo(1, 6360.37988f, 490.54800f, 18.2588f, 0.0f);
		break;
	case 603: // Kalimdor -> Desolace
		player->CLOSE_GOSSIP_MENU();
		player->TeleportTo(1, -93.1614f, 1691.15f, 90.0649f, 0.0f);
		break;
	case 604: // Kalimdor -> Durotar
		player->CLOSE_GOSSIP_MENU();
		player->TeleportTo(1, 341.42f, -4684.7f, 31.9493f, 0.0f);
		break;
	case 605: // Kalimdor -> Duswallow Marsh
		player->CLOSE_GOSSIP_MENU();
		player->TeleportTo(1, -3463.26f, -4123.13f, 18.1043f, 0.0f);
		break;
	case 606: // Kalimdor -> Ferelas
		player->CLOSE_GOSSIP_MENU();
		player->TeleportTo(1, -4458.93f, 243.415f, 65.6136f, 0.0f);
		break;
	case 607: // Kalimdor -> Silithus
		player->CLOSE_GOSSIP_MENU();
		player->TeleportTo(1, -6824.15f, 821.273f, 50.6675f, 0.0f);
		break;
	case 608: // Kalimdor -> Stonetalon Mountains
		player->CLOSE_GOSSIP_MENU();
		player->TeleportTo(1, 1145.00f, 85.664f, -6.64f, 0.0f);
		break;
	case 609: // Kalimdor -> Tanaris
		player->CLOSE_GOSSIP_MENU();
		player->TeleportTo(1, -7177.743f, -3786.3007f, 8.3702f, 2.737f);
		//player->TeleportTo(1, -7373.69f, -2950.2f, 11.7598f, 0.0f);
		break;
	case 610: // Kalimdor -> The Barrens
		player->CLOSE_GOSSIP_MENU();
		player->TeleportTo(1, -456.263f, -2652.7f, 96.615f, 0.0f);
		break;
	case 611: // Kalimdor -> Thousand Needles
		player->CLOSE_GOSSIP_MENU();
		player->TeleportTo(1, -4941.66f, -1595.42f, -33.07f, 0.0f);
		break;
	case 612: // Kalimdor -> ������
		player->CLOSE_GOSSIP_MENU();
		player->TeleportTo(1, 6723.56f, -4645.23f, 721.78f, 0.0f);
		break;
	case 613: // Eastern Kingdoms -> Arathi Highlands
		player->CLOSE_GOSSIP_MENU();
		player->TeleportTo(0, -1544.93f, -2495.01f, 54.11f, 0.0f);
		break;
	case 614: // Eastern Kingdoms -> Badlands
		player->CLOSE_GOSSIP_MENU();
		player->TeleportTo(0, -6084.95f, -3328.44f, 253.76f, 0.0f);
		break;
	case 615: // Eastern Kingdoms -> Dun Morogh
		player->CLOSE_GOSSIP_MENU();
		player->TeleportTo(0, -5614.06f, -482.954f, 396.981f, 0.0f);
		break;
	case 616: // Eastern Kingdoms -> ĺɫɭ��
		player->CLOSE_GOSSIP_MENU();
		player->TeleportTo(0, -10879.85f, -327.06f, 37.78f, 0.0f);
		break;
	case 617: // Eastern Kingdoms -> Eastern Plaguelands
		player->CLOSE_GOSSIP_MENU();
		player->TeleportTo(0, 2280.12f, -5313.16f, 87.74f, 0.0f);
		break;
	case 618: // Eastern Kingdoms -> ������
		player->CLOSE_GOSSIP_MENU();
		player->TeleportTo(0, -9457.6396f, 99.6884f, 58.4271f, 0.0f);
		break;
	case 619: // Eastern Kingdoms -> Hillsbrad Foothills
		player->CLOSE_GOSSIP_MENU();
		player->TeleportTo(0, -436.03f, -583.27f, 53.58f, 0.0f);
		break;
	case 620: // Eastern Kingdoms -> �༹ɽ
		player->CLOSE_GOSSIP_MENU();
		player->TeleportTo(0, -9343.565430f, -2246.52417f, 72.1076f, 0.0f);
		break;
	case 621: // Eastern Kingdoms -> Silverpine Forest
		player->CLOSE_GOSSIP_MENU();
		player->TeleportTo(0, 641.48f, 1297.84f, 85.45f, 0.0f);
		break;
	case 622: // Eastern Kingdoms -> Stranglethorn Vale
		player->CLOSE_GOSSIP_MENU();
		player->TeleportTo(0, -11818.88f, 1241.7f, 1.587f, 0.0f);
		break;
	case 623: // Eastern Kingdoms -> Swamp of Sorrows
		player->CLOSE_GOSSIP_MENU();
		player->TeleportTo(0, -10522.55f, -3028.30f, 21.79f, 0.0f);
		break;
	case 624: // Eastern Kingdoms -> The Hinterlands
		player->CLOSE_GOSSIP_MENU();
		player->TeleportTo(0, 155.14f, -2014.95f, 122.55f, 0.0f);
		break;
	case 625: // Eastern Kingdoms -> Tirishfal Glades
		player->CLOSE_GOSSIP_MENU();
		player->TeleportTo(0, 2255.5f, 288.511f, 35.1138f, 0.0f);
		break;
	case 626: // Eastern Kingdoms -> �ڱ���
		player->CLOSE_GOSSIP_MENU();
		player->TeleportTo(0, -10498.347656f, 1036.45239f, 96.1105f, 0.0f);
		break;
	case 627: // Eastern Kingdoms -> ����ϣ����
		player->CLOSE_GOSSIP_MENU();
		player->TeleportTo(0, -3740.29f, -755.08f, 10.9643f, 0.0f);
		break;
	case 628: // Kalimdor -> ���ݳ�
		player->CLOSE_GOSSIP_MENU();
		player->TeleportTo(1, -977.01f, -3788.01f, 6.01f, 0.0f);
		break;
	case 629: // Eastern Kingdoms  -> �ر�����
		player->CLOSE_GOSSIP_MENU();
		player->TeleportTo(0, -14302.001f, 518.001f, 9.001f, 0.0f);
		break;
	case 630: // Eastern Kingdoms  -> ���ȷ�ľ��
		player->CLOSE_GOSSIP_MENU();
		player->TeleportTo(0, -9549.00f, -1407.04f, 54.7673f, 0.0f);
		break;
	case 631: // Eastern Kingdoms  -> ������
		player->CLOSE_GOSSIP_MENU();
		player->TeleportTo(1, 3546.8f, -5287.96f, 109.935f, 0.0f);
		break;
	case 632: // Eastern Kingdoms  -> �����ӻ���ɽ
		player->CLOSE_GOSSIP_MENU();
		player->TeleportTo(1, -6834.8203f, -1515.5482f, -262.3182f, 0.0f);
		break;


		// ---### Ұ��BOSS ###---

	case 5000: // ĺɫɭ��
		player->CLOSE_GOSSIP_MENU();
		player->TeleportTo(0, -10526.1689f, -434.9967f, 50.894f, 0.0f);
		break;
	case 5001: // ������
		player->CLOSE_GOSSIP_MENU();
		player->TeleportTo(0, 759.6057f, -3893.3413f, 116.4753f, 0.0f);
		break;
	case 5002: // �ҹ�
		player->CLOSE_GOSSIP_MENU();
		player->TeleportTo(1, 3120.2893f, -3439.4443f, 139.5663f, 0.0f);
		break;
	case 5003: // ������
		player->CLOSE_GOSSIP_MENU();
		player->TeleportTo(1, 2622.22f, -5977.930f, 100.5629f, 0.0f);
		break;
	case 5004: // ����˹
		player->CLOSE_GOSSIP_MENU();
		player->TeleportTo(1, -2741.2900f, 2009.4813f, 31.8773f, 0.0f);
		break;
	case 5005: // ����֮��
		player->CLOSE_GOSSIP_MENU();
		player->TeleportTo(0, -12234.00f, -2474.00f, -3.00f, 0.0f);
		break;
	case 5006: // ϣ����˹
		player->CLOSE_GOSSIP_MENU();
		player->TeleportTo(1, -6292.4633f, 1578.0290f, 0.1553f, 0.0f);
		break;


		// ---### ������� ###---

	case 700: // �����޺���
		player->CLOSE_GOSSIP_MENU();
		player->TeleportTo(0, -11037.7f, -1999.49f, 92.9823f, 0.0f);
		break;
	case 701: // ǧ��ʯ��
		player->CLOSE_GOSSIP_MENU();
		player->TeleportTo(1, -4885.001f, -1596.001f, 101.001f, 0.0f);
		break;
	case 702: // ��������
		player->CLOSE_GOSSIP_MENU();
		player->TeleportTo(369, -9.96166f, 1238.17f, -126.102f, 0.0f);
		break;
	case 703: // ��¯��ɽ��
		player->CLOSE_GOSSIP_MENU();
		player->TeleportTo(0, -4794.76f, -1002.07f, 896.28f, 0.0f);
		break;
	case 704: // ���Ӷ�ɽ
		player->CLOSE_GOSSIP_MENU();
		player->TeleportTo(1, 4603.9467f, -3879.2509f, 944.1834f, 0.0f);
		break;
	case 705: // ���Ϻ���
		player->CLOSE_GOSSIP_MENU();
		player->TeleportTo(269, 2386.246338f, 1182.790283f, 67.265854f, 0.0f);
		break;
		//case 706: // ���ɭ��
		//player->CLOSE_GOSSIP_MENU();
		//player->TeleportTo(169, 3105.41f, 3096.78f, 27.0032f, 0.0f);
		//break;
	case 707: // GM��
		player->CLOSE_GOSSIP_MENU();
		player->TeleportTo(1, 16225.86f, 16282.23f, 13.1749f, 0.0f);
		break;

	case 100: // Main Menu
			  // HORDE
		if (player->GetTeam() == HORDE)
		{
			//player->ADD_GOSSIP_ITEM(5, "PreTBC Mall" , GOSSIP_SENDER_MAIN, 74);
			player->ADD_GOSSIP_ITEM(5, "���Ǵ���", GOSSIP_SENDER_MAIN, 1);
			player->ADD_GOSSIP_ITEM(5, "��ʼ֮��", GOSSIP_SENDER_MAIN, 3);
			player->ADD_GOSSIP_ITEM(5, "���˸���", GOSSIP_SENDER_MAIN, 5);
			player->ADD_GOSSIP_ITEM(5, "�ŶӸ���", GOSSIP_SENDER_MAIN, 101);
			player->ADD_GOSSIP_ITEM(5, "ս���ٻ�", GOSSIP_SENDER_MAIN, 10);
			player->ADD_GOSSIP_ITEM(5, "Ұ��BOSS", GOSSIP_SENDER_MAIN, 6000);
			player->ADD_GOSSIP_ITEM(5, "����ķ��", GOSSIP_SENDER_MAIN, 6010);
			player->ADD_GOSSIP_ITEM(5, "��������", GOSSIP_SENDER_MAIN, 6020);
			player->ADD_GOSSIP_ITEM(5, "�������", GOSSIP_SENDER_MAIN, 6030);

			player->SEND_GOSSIP_MENU(DEFAULT_GOSSIP_MESSAGE, _Creature->GetGUID());
		}
		// ALLIANCE
		else
		{
			//player->ADD_GOSSIP_ITEM(5, "PreTBC Mall" , GOSSIP_SENDER_MAIN, 74);
			player->ADD_GOSSIP_ITEM(5, "���Ǵ���", GOSSIP_SENDER_MAIN, 2);
			player->ADD_GOSSIP_ITEM(5, "��ʼ֮��", GOSSIP_SENDER_MAIN, 4);
			player->ADD_GOSSIP_ITEM(5, "���˸���", GOSSIP_SENDER_MAIN, 5);
			player->ADD_GOSSIP_ITEM(5, "�ŶӸ���", GOSSIP_SENDER_MAIN, 101);
			player->ADD_GOSSIP_ITEM(5, "ս���ٻ�", GOSSIP_SENDER_MAIN, 11);
			player->ADD_GOSSIP_ITEM(5, "Ұ��BOSS", GOSSIP_SENDER_MAIN, 6000);
			player->ADD_GOSSIP_ITEM(5, "����ķ��", GOSSIP_SENDER_MAIN, 6010);
			player->ADD_GOSSIP_ITEM(5, "��������", GOSSIP_SENDER_MAIN, 6020);
			player->ADD_GOSSIP_ITEM(5, "�������", GOSSIP_SENDER_MAIN, 6030);

			player->SEND_GOSSIP_MENU(DEFAULT_GOSSIP_MESSAGE, _Creature->GetGUID());
		}
		break;
	}
}
bool GossipSelect_TeleportNPC(Player* player, Creature* _Creature, uint32 sender, uint32 action)
{
	// Main menu
	if (sender == GOSSIP_SENDER_MAIN)
		SendDefaultMenu_TeleportNPC(player, _Creature, action);

	return true;
}

enum Enchants
{
	WEP2H_SUPERIOR_IMPACT = 20,
	WEP2H_AGILITY,
	WEP_CRUSADER,
	WEP1H_AGILITY,
	WEP_SPELLPOWER,
	WEP_HEAL,
	OFFHAND_SPIRIT,
	OFFHAND_STAM,
	OFFHAND_FROSTRES,
	CHEST_STATS,
	CLOAK_DODGE,
	CLOAK_SUB,
	CLOAK_ARMOR,
	CLOAK_AGILITY,
	BRACER_STAM,
	BRACER_STR,
	BRACER_HEAL,
	BRACER_INT,
	GLOVES_AGI,
	GLOVES_FIRE,
	GLOVES_FROST,
	GLOVES_SHADOW,
	GLOVES_HEALING,
	BOOTS_AGI,
	BOOTS_SPEED,
	BOOTS_STAM,
	WEP_RANGE,
};

void Enchant(Player* player, Item* item, uint32 enchantid)
{
	if (!item)
	{
		player->GetSession()->SendNotification("�������װ����Ҫ��ħ����Ʒ.");
		return;
	}

	if (!enchantid)
	{
		player->GetSession()->SendNotification("���˵�����.");
		return;
	}

	item->ClearEnchantment(PERM_ENCHANTMENT_SLOT);
	item->SetEnchantment(PERM_ENCHANTMENT_SLOT, enchantid, 0, 0);
	player->GetSession()->SendNotification("|cff4CFF00����|cffDA70D6%s�Ѹ�ħ�ɹ�", item->GetProto()->Name1);
}

bool GossipHello_EnchantNPC(Player* player, Creature* creature)
{

	player->ADD_GOSSIP_ITEM(5, "�ز�", GOSSIP_SENDER_MAIN, EQUIPMENT_SLOT_CHEST);
	player->ADD_GOSSIP_ITEM(5, "����", GOSSIP_SENDER_MAIN, EQUIPMENT_SLOT_BACK);
	player->ADD_GOSSIP_ITEM(5, "����", GOSSIP_SENDER_MAIN, EQUIPMENT_SLOT_WRISTS);
	player->ADD_GOSSIP_ITEM(5, "����", GOSSIP_SENDER_MAIN, EQUIPMENT_SLOT_HANDS);
	player->ADD_GOSSIP_ITEM(5, "ѥ��", GOSSIP_SENDER_MAIN, EQUIPMENT_SLOT_FEET);
	player->ADD_GOSSIP_ITEM(5, "����", GOSSIP_SENDER_MAIN, EQUIPMENT_SLOT_MAINHAND);
	player->ADD_GOSSIP_ITEM(5, "����", GOSSIP_SENDER_MAIN, EQUIPMENT_SLOT_OFFHAND);

	player->SEND_GOSSIP_MENU(player->GetGossipTextId(creature), creature->GetGUID());
	return true;
}
bool GossipSelect_EnchantNPC(Player* player, Creature* creature, uint32 sender, uint32 action)
{
	if (sender != GOSSIP_SENDER_MAIN)
		return true;

	if (action < 20)
	{
		switch (action)
		{
		case EQUIPMENT_SLOT_CHEST:
			player->ADD_GOSSIP_ITEM(5, "��������+4", GOSSIP_SENDER_MAIN, CHEST_STATS);
			break;
		case EQUIPMENT_SLOT_BACK:
			player->ADD_GOSSIP_ITEM(5, "����+3", GOSSIP_SENDER_MAIN, CLOAK_AGILITY);
			player->ADD_GOSSIP_ITEM(5, "����+70", GOSSIP_SENDER_MAIN, CLOAK_ARMOR);
			player->ADD_GOSSIP_ITEM(5, "����+1%", GOSSIP_SENDER_MAIN, CLOAK_DODGE);
			player->ADD_GOSSIP_ITEM(5, "��թ", GOSSIP_SENDER_MAIN, CLOAK_SUB);
			break;
		case EQUIPMENT_SLOT_WRISTS:
			player->ADD_GOSSIP_ITEM(5, "����+9", GOSSIP_SENDER_MAIN, BRACER_STAM);
			player->ADD_GOSSIP_ITEM(5, "����+9", GOSSIP_SENDER_MAIN, BRACER_STR);
			player->ADD_GOSSIP_ITEM(5, "���Ʒ���+24", GOSSIP_SENDER_MAIN, BRACER_HEAL);
			player->ADD_GOSSIP_ITEM(5, "����+7", GOSSIP_SENDER_MAIN, BRACER_INT);
			break;
		case EQUIPMENT_SLOT_HANDS:
			player->ADD_GOSSIP_ITEM(5, "����+15", GOSSIP_SENDER_MAIN, GLOVES_AGI);
			player->ADD_GOSSIP_ITEM(5, "�����˺�+20", GOSSIP_SENDER_MAIN, GLOVES_FIRE);
			player->ADD_GOSSIP_ITEM(5, "��˪�˺�+20", GOSSIP_SENDER_MAIN, GLOVES_FROST);
			player->ADD_GOSSIP_ITEM(5, "��Ӱ�˺�+20", GOSSIP_SENDER_MAIN, GLOVES_SHADOW);
			player->ADD_GOSSIP_ITEM(5, "���Ʒ���+30", GOSSIP_SENDER_MAIN, GLOVES_HEALING);
			break;
		case EQUIPMENT_SLOT_FEET:
			player->ADD_GOSSIP_ITEM(5, "����+7", GOSSIP_SENDER_MAIN, BOOTS_STAM);
			player->ADD_GOSSIP_ITEM(5, "�ƶ��ٶ�", GOSSIP_SENDER_MAIN, BOOTS_SPEED);
			player->ADD_GOSSIP_ITEM(5, "����+5", GOSSIP_SENDER_MAIN, BOOTS_AGI);
			break;
		case EQUIPMENT_SLOT_MAINHAND:
			player->ADD_GOSSIP_ITEM(5, "ʮ�־�", GOSSIP_SENDER_MAIN, WEP_CRUSADER);
			player->ADD_GOSSIP_ITEM(5, "15����", GOSSIP_SENDER_MAIN, WEP1H_AGILITY);
			player->ADD_GOSSIP_ITEM(5, "25����", GOSSIP_SENDER_MAIN, WEP2H_AGILITY);
			player->ADD_GOSSIP_ITEM(5, "�����˺�+30", GOSSIP_SENDER_MAIN, WEP_SPELLPOWER);
			player->ADD_GOSSIP_ITEM(5, "���Ʒ���+55", GOSSIP_SENDER_MAIN, WEP_HEAL);
			break;
		case EQUIPMENT_SLOT_OFFHAND:
			player->ADD_GOSSIP_ITEM(5, "����+9", GOSSIP_SENDER_MAIN, OFFHAND_SPIRIT);
			player->ADD_GOSSIP_ITEM(5, "����+7", GOSSIP_SENDER_MAIN, OFFHAND_STAM);
			player->ADD_GOSSIP_ITEM(5, "��˪����+8", GOSSIP_SENDER_MAIN, OFFHAND_FROSTRES);
			break;
		}
		player->SEND_GOSSIP_MENU(DEFAULT_GOSSIP_MESSAGE, creature->GetGUID());
	}
	else
	{
		Item* item = nullptr;
		uint32 id = 0;
		switch (action)
		{
		case WEP2H_SUPERIOR_IMPACT:
		case WEP2H_AGILITY:
			item = player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_MAINHAND);
			if (item && (action == WEP2H_AGILITY || action == WEP2H_SUPERIOR_IMPACT))
			{
				if (item->GetProto()->SubClass != ITEM_SUBCLASS_WEAPON_AXE2 && item->GetProto()->SubClass != ITEM_SUBCLASS_WEAPON_MACE2
					&& item->GetProto()->SubClass != ITEM_SUBCLASS_WEAPON_SWORD2 && item->GetProto()->SubClass != ITEM_SUBCLASS_WEAPON_POLEARM
					&& item->GetProto()->SubClass != ITEM_SUBCLASS_WEAPON_STAFF)
				{
					player->GetSession()->SendNotification("��Ҫ��װ��˫������");
					player->CLOSE_GOSSIP_MENU();
					return true;
				}
			}
			if (action == WEP2H_SUPERIOR_IMPACT)
				id = 1896;
			else if (action == WEP2H_AGILITY)
				id = 2646;
			break;

		case WEP_CRUSADER:
			item = player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_MAINHAND);
			id = 1900;
			break;
		case WEP1H_AGILITY:
			item = player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_MAINHAND);
			id = 2564;
			break;
		case WEP_SPELLPOWER:
			item = player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_MAINHAND);
			id = 2504;
			break;
		case WEP_HEAL:
			item = player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_MAINHAND);
			id = 2505;
			break;

		case OFFHAND_SPIRIT:
		case OFFHAND_STAM:
		case OFFHAND_FROSTRES:
			item = player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_OFFHAND);
			if (item && item->GetProto()->SubClass != ITEM_SUBCLASS_ARMOR_SHIELD)
			{
				player->GetSession()->SendNotification("����Ҫ��װ������");
				player->CLOSE_GOSSIP_MENU();
				return true;
			}
			if (action == OFFHAND_SPIRIT)
				id = 1890;
			else if (action == OFFHAND_FROSTRES)
				id = 926;
			else if (action == OFFHAND_STAM)
				id = 929;
			break;
		case CHEST_STATS:
			item = player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_CHEST);
			id = 1891;
			break;
		case CLOAK_DODGE:
			item = player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_BACK);
			id = 2622;
			break;
		case CLOAK_SUB:
			item = player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_BACK);
			id = 2621;
			break;
		case CLOAK_ARMOR:
			item = player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_BACK);
			id = 1889;
			break;
		case CLOAK_AGILITY:
			item = player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_BACK);
			id = 849;
			break;
		case BRACER_STAM:
			item = player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_WRISTS);
			id = 1886;
			break;
		case BRACER_STR:
			item = player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_WRISTS);
			id = 1885;
			break;
		case BRACER_HEAL:
			item = player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_WRISTS);
			id = 2566;
			break;
		case BRACER_INT:
			item = player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_WRISTS);
			id = 1883;
			break;
		case GLOVES_AGI:
			item = player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_HANDS);
			id = 2564;
			break;
		case GLOVES_FIRE:
			item = player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_HANDS);
			id = 2616;
			break;
		case GLOVES_FROST:
			item = player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_HANDS);
			id = 2615;
			break;
		case GLOVES_SHADOW:
			item = player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_HANDS);
			id = 2614;
			break;
		case GLOVES_HEALING:
			item = player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_HANDS);
			id = 2617;
			break;
		case BOOTS_AGI:
			item = player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_FEET);
			id = 904;
			break;
		case BOOTS_SPEED:
			item = player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_FEET);
			id = 911;
			break;
		case BOOTS_STAM:
			item = player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_FEET);
			id = 929;
			break;
		}
		Enchant(player, item, id);
		player->CLOSE_GOSSIP_MENU();
	}
	return true;
}



void EnchantCZ(Player* player, Item* item, uint32 enchantid)
{
	if (!item)
	{
		//player->GetSession()->SendNotification("�������װ����Ҫ��ħ����Ʒ.");
		player->GetSession()->SendNotification("�������װ����Ҫϴ������Ʒ.");

		return;
	}

	//if (!enchantid)
	//{
	//	player->GetSession()->SendNotification("���˵�����.");
	//	return;
	//}

	if (player->HasItemCount(42053,1))
	{
		int itemID = 0;
		itemID = item->GetProto()->ItemId;
		player->DestroyItemCount(42053, 1, true, false);
		//player->DestroyItemCount(itemID, 1, true, false);
		player->DestroyEquippedItem(itemID);
		player->AddItem(itemID, 1);
		
		//
		//int itemID2 = 0;
		//itemID2 = item->GetObjectGuid();
		//player->SendLoot(itemID2, LOOT_CORPSE);
		//

		//
		player->GetSession()->SendNotification("|cff4CFF00����|cffDA70D6%s��ϴ���ɹ�,�뿴����!", item->GetProto()->Name1);
		player->CLOSE_GOSSIP_MENU();





	}

	else
	{

		player->GetSession()->SendNotification("|cff4CFF00����|ԭʼ��ʯ����.");
		player->CLOSE_GOSSIP_MENU();

	}



	//item->ClearEnchantment(PERM_ENCHANTMENT_SLOT);
	//item->SetEnchantment(PERM_ENCHANTMENT_SLOT, enchantid, 0, 0);
	//player->GetSession()->SendNotification("|cff4CFF00����|cffDA70D6%s�Ѹ�ħ�ɹ�", item->GetProto()->Name1);
}

bool GossipHello_EnchantCZNPC(Player* player, Creature* creature)
{
	//	char* tmp = new char[100];
	//sprintf(tmp, "|cFF0041FF����ע��!����ѡ���������װ�����ж�Ӧ��װ��,���ɳ���,��ע��!|r ", 0);
	player->ADD_GOSSIP_ITEM(4, "|cFF0041FF����ע��!����ѡ���������װ�����ж�Ӧ��װ��,���ɳ���,��ע��|r", GOSSIP_SENDER_MAIN, 0);

	player->ADD_GOSSIP_ITEM(5, "�����ؼ�-> ����1ԭʼ��ʯ", GOSSIP_SENDER_MAIN, EQUIPMENT_SLOT_CHEST);
	player->ADD_GOSSIP_ITEM(5, "��������-> ����1ԭʼ��ʯ", GOSSIP_SENDER_MAIN, EQUIPMENT_SLOT_BACK);
	player->ADD_GOSSIP_ITEM(5, "���û���-> ����1ԭʼ��ʯ", GOSSIP_SENDER_MAIN, EQUIPMENT_SLOT_WRISTS);
	player->ADD_GOSSIP_ITEM(5, "���û���-> ����1ԭʼ��ʯ", GOSSIP_SENDER_MAIN, EQUIPMENT_SLOT_HANDS);
	player->ADD_GOSSIP_ITEM(5, "����ѥ��-> ����1ԭʼ��ʯ", GOSSIP_SENDER_MAIN, EQUIPMENT_SLOT_FEET);
	player->ADD_GOSSIP_ITEM(5, "��������-> ����1ԭʼ��ʯ", GOSSIP_SENDER_MAIN, EQUIPMENT_SLOT_MAINHAND);
	player->ADD_GOSSIP_ITEM(5, "���ø���-> ����1ԭʼ��ʯ", GOSSIP_SENDER_MAIN, EQUIPMENT_SLOT_OFFHAND);
	player->ADD_GOSSIP_ITEM(5, "����Զ��������-> ����1ԭʼ��ʯ", GOSSIP_SENDER_MAIN, EQUIPMENT_SLOT_RANGED);


	player->SEND_GOSSIP_MENU(player->GetGossipTextId(creature), creature->GetGUID());
	return true;
}
bool GossipSelect_EnchantCZNPC(Player* player, Creature* creature, uint32 sender, uint32 action)
{
	if (sender != GOSSIP_SENDER_MAIN)
		return true;

	if (action < 20)
	{
		switch (action)
		{
		case EQUIPMENT_SLOT_CHEST:
			player->ADD_GOSSIP_ITEM(5, "��ȷ��! װ��������Ʒ������", GOSSIP_SENDER_MAIN, CHEST_STATS);
			break;
		case EQUIPMENT_SLOT_BACK:
			player->ADD_GOSSIP_ITEM(5, "��ȷ��! װ��������Ʒ������", GOSSIP_SENDER_MAIN, CLOAK_AGILITY);
			//player->ADD_GOSSIP_ITEM(5, "����+70", GOSSIP_SENDER_MAIN, CLOAK_ARMOR);
			//player->ADD_GOSSIP_ITEM(5, "����+1%", GOSSIP_SENDER_MAIN, CLOAK_DODGE);
			//player->ADD_GOSSIP_ITEM(5, "��թ", GOSSIP_SENDER_MAIN, CLOAK_SUB);
			break;
		case EQUIPMENT_SLOT_WRISTS:
			player->ADD_GOSSIP_ITEM(5, "��ȷ��! װ��������Ʒ������", GOSSIP_SENDER_MAIN, BRACER_STAM);
			//player->ADD_GOSSIP_ITEM(5, "����+9", GOSSIP_SENDER_MAIN, BRACER_STR);
			//player->ADD_GOSSIP_ITEM(5, "���Ʒ���+24", GOSSIP_SENDER_MAIN, BRACER_HEAL);
			//player->ADD_GOSSIP_ITEM(5, "����+7", GOSSIP_SENDER_MAIN, BRACER_INT);
			break;
		case EQUIPMENT_SLOT_HANDS:
			player->ADD_GOSSIP_ITEM(5, "��ȷ��! װ��������Ʒ������", GOSSIP_SENDER_MAIN, GLOVES_AGI);
			//player->ADD_GOSSIP_ITEM(5, "�����˺�+20", GOSSIP_SENDER_MAIN, GLOVES_FIRE);
			//player->ADD_GOSSIP_ITEM(5, "��˪�˺�+20", GOSSIP_SENDER_MAIN, GLOVES_FROST);
			//player->ADD_GOSSIP_ITEM(5, "��Ӱ�˺�+20", GOSSIP_SENDER_MAIN, GLOVES_SHADOW);
			//player->ADD_GOSSIP_ITEM(5, "���Ʒ���+30", GOSSIP_SENDER_MAIN, GLOVES_HEALING);
			break;
		case EQUIPMENT_SLOT_FEET:
			player->ADD_GOSSIP_ITEM(5, "��ȷ��! װ��������Ʒ������", GOSSIP_SENDER_MAIN, BOOTS_STAM);
			//player->ADD_GOSSIP_ITEM(5, "�ƶ��ٶ�", GOSSIP_SENDER_MAIN, BOOTS_SPEED);
			//player->ADD_GOSSIP_ITEM(5, "����+5", GOSSIP_SENDER_MAIN, BOOTS_AGI);
			break;
		case EQUIPMENT_SLOT_MAINHAND:
			player->ADD_GOSSIP_ITEM(5, "��ȷ��! װ��������Ʒ������", GOSSIP_SENDER_MAIN, WEP_CRUSADER);
			//player->ADD_GOSSIP_ITEM(5, "15����", GOSSIP_SENDER_MAIN, WEP1H_AGILITY);
			//player->ADD_GOSSIP_ITEM(5, "25����", GOSSIP_SENDER_MAIN, WEP2H_AGILITY);
			//player->ADD_GOSSIP_ITEM(5, "�����˺�+30", GOSSIP_SENDER_MAIN, WEP_SPELLPOWER);
			//player->ADD_GOSSIP_ITEM(5, "���Ʒ���+55", GOSSIP_SENDER_MAIN, WEP_HEAL);
			break;
		case EQUIPMENT_SLOT_OFFHAND:
			//player->ADD_GOSSIP_ITEM(5, "��ȷ��! װ��������Ʒ������", GOSSIP_SENDER_MAIN, OFFHAND_SPIRIT);
			player->ADD_GOSSIP_ITEM(5, "��ȷ��! װ��������Ʒ������", GOSSIP_SENDER_MAIN, OFFHAND_STAM);
			//player->ADD_GOSSIP_ITEM(5, "��˪����+8", GOSSIP_SENDER_MAIN, OFFHAND_FROSTRES);
			break;

		case  EQUIPMENT_SLOT_RANGED:

			player->ADD_GOSSIP_ITEM(5, "��ȷ��! װ��������Ʒ������", GOSSIP_SENDER_MAIN, WEP_RANGE);
				
			break;



		}
		player->SEND_GOSSIP_MENU(DEFAULT_GOSSIP_MESSAGE, creature->GetGUID());
	}
	else
	{
		Item* item = nullptr;
		uint32 id = 0;
		switch (action)
		{
		case WEP2H_SUPERIOR_IMPACT:
		case WEP2H_AGILITY:
			item = player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_MAINHAND);
			if (item && (action == WEP2H_AGILITY || action == WEP2H_SUPERIOR_IMPACT))
			{
				if (item->GetProto()->SubClass != ITEM_SUBCLASS_WEAPON_AXE2 && item->GetProto()->SubClass != ITEM_SUBCLASS_WEAPON_MACE2
					&& item->GetProto()->SubClass != ITEM_SUBCLASS_WEAPON_SWORD2 && item->GetProto()->SubClass != ITEM_SUBCLASS_WEAPON_POLEARM
					&& item->GetProto()->SubClass != ITEM_SUBCLASS_WEAPON_STAFF)
				{
					player->GetSession()->SendNotification("��Ҫ��װ��˫������");
					player->CLOSE_GOSSIP_MENU();
					return true;
				}
			}
			if (action == WEP2H_SUPERIOR_IMPACT)
				id = 1896;
			else if (action == WEP2H_AGILITY)
				id = 2646;
			break;

		case WEP_CRUSADER:
			item = player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_MAINHAND);
			id = 1900;
			break;
		case WEP1H_AGILITY:
			item = player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_MAINHAND);
			id = 2564;
			break;
		case WEP_SPELLPOWER:
			item = player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_MAINHAND);
			id = 2504;
			break;
		case WEP_HEAL:
			item = player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_MAINHAND);
			id = 2505;
			break;

		case OFFHAND_SPIRIT:
		case OFFHAND_STAM:
		case OFFHAND_FROSTRES:
			item = player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_OFFHAND);
			//if (item && item->GetProto()->SubClass != ITEM_SUBCLASS_ARMOR_SHIELD)
			//{
			//	player->GetSession()->SendNotification("����Ҫ��װ������");
			//	player->CLOSE_GOSSIP_MENU();
			//	return true;
			//}
			//if (action == OFFHAND_SPIRIT)
			//	id = 1890;
			//else if (action == OFFHAND_FROSTRES)
			//	id = 926;
			//else if (action == OFFHAND_STAM)
			/*	id = 929;*/
			break;
		case CHEST_STATS:
			item = player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_CHEST);
			id = 1891;
			break;
		case CLOAK_DODGE:
			item = player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_BACK);
			id = 2622;
			break;
		case CLOAK_SUB:
			item = player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_BACK);
			id = 2621;
			break;
		case CLOAK_ARMOR:
			item = player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_BACK);
			id = 1889;
			break;
		case CLOAK_AGILITY:
			item = player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_BACK);
			id = 849;
			break;
		case BRACER_STAM:
			item = player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_WRISTS);
			id = 1886;
			break;
		case BRACER_STR:
			item = player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_WRISTS);
			id = 1885;
			break;
		case BRACER_HEAL:
			item = player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_WRISTS);
			id = 2566;
			break;
		case BRACER_INT:
			item = player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_WRISTS);
			id = 1883;
			break;
		case GLOVES_AGI:
			item = player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_HANDS);
			id = 2564;
			break;
		case GLOVES_FIRE:
			item = player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_HANDS);
			id = 2616;
			break;
		case GLOVES_FROST:
			item = player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_HANDS);
			id = 2615;
			break;
		case GLOVES_SHADOW:
			item = player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_HANDS);
			id = 2614;
			break;
		case GLOVES_HEALING:
			item = player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_HANDS);
			id = 2617;
			break;
		case BOOTS_AGI:
			item = player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_FEET);
			id = 904;
			break;
		case BOOTS_SPEED:
			item = player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_FEET);
			id = 911;
			break;
		case BOOTS_STAM:
			item = player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_FEET);
			id = 929;
			break;

		case WEP_RANGE:
			item = player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_RANGED);
			id = 929;
			break;
		}
		EnchantCZ(player, item, id);
		player->CLOSE_GOSSIP_MENU();
	}
	return true;
}



void LearnSkillRecipesHelper(Player* player, uint32 skill_id)
{
	uint32 classmask = player->GetClassMask();

	for (uint32 j = 0; j < sObjectMgr.GetMaxSkillLineAbilityId(); ++j)
	{
		SkillLineAbilityEntry const* skillLine = sObjectMgr.GetSkillLineAbility(j);
		if (!skillLine)
			continue;

		// wrong skill
		if (skillLine->skillId != skill_id)
			continue;

		// not high rank
		if (skillLine->forward_spellid)
			continue;

		// skip racial skills
		if (skillLine->racemask != 0)
			continue;

		// skip wrong class skills
		if (skillLine->classmask && (skillLine->classmask & classmask) == 0)
			continue;

		SpellEntry const* spellEntry = sSpellMgr.GetSpellEntry(skillLine->spellId);
		if (!spellEntry || !SpellMgr::IsSpellValid(spellEntry, player, false))
			continue;

		player->LearnSpell(skillLine->spellId, false);
	}
}
bool LearnAllRecipesInProfession(Player* pPlayer, SkillType skill)
{
	ChatHandler handler(pPlayer->GetSession());
	char* skill_name;

	SkillLineEntry const* SkillInfo = sSkillLineStore.LookupEntry(skill);
	skill_name = SkillInfo->name[sWorld.GetDefaultDbcLocale()];

	if (!SkillInfo)
	{
		sLog.outError("Profession NPC: received non-valid skill ID");
		return false;
	}

	pPlayer->SetSkill(SkillInfo->id, 300, 300);
	LearnSkillRecipesHelper(pPlayer, SkillInfo->id);
	pPlayer->GetSession()->SendNotification("|cff4CFF00���Ѿ���ѧ����|cffDA70D6%sȫ������", skill_name);
	return true;
}

bool GossipHello_ProfessionNPC(Player* player, Creature* creature)
{

	player->ADD_GOSSIP_ITEM(GOSSIP_ICON_INTERACT_2, "����-> ����5��ԭʼ��ʯ", GOSSIP_SENDER_MAIN, 1);
	player->ADD_GOSSIP_ITEM(GOSSIP_ICON_INTERACT_2, "����-> ����5��ԭʼ��ʯ", GOSSIP_SENDER_MAIN, 2);
	player->ADD_GOSSIP_ITEM(GOSSIP_ICON_INTERACT_2, "��Ƥ-> ����5��ԭʼ��ʯ", GOSSIP_SENDER_MAIN, 3);
	player->ADD_GOSSIP_ITEM(GOSSIP_ICON_INTERACT_2, "�÷�-> ����5��ԭʼ��ʯ", GOSSIP_SENDER_MAIN, 4);
	player->ADD_GOSSIP_ITEM(GOSSIP_ICON_INTERACT_2, "����-> ����5��ԭʼ��ʯ", GOSSIP_SENDER_MAIN, 5);
	player->ADD_GOSSIP_ITEM(GOSSIP_ICON_INTERACT_2, "��ħ-> ����5��ԭʼ��ʯ", GOSSIP_SENDER_MAIN, 6);
	//player->ADD_GOSSIP_ITEM(GOSSIP_ICON_INTERACT_2, "�鱦�ӹ�" , GOSSIP_SENDER_MAIN, 7);
	//player->ADD_GOSSIP_ITEM(GOSSIP_ICON_INTERACT_2, "����" , GOSSIP_SENDER_MAIN, 8);
	player->ADD_GOSSIP_ITEM(GOSSIP_ICON_INTERACT_2, "��ҩ-> ����5��ԭʼ��ʯ", GOSSIP_SENDER_MAIN, 9);
	player->ADD_GOSSIP_ITEM(GOSSIP_ICON_INTERACT_2, "��Ƥ-> ����5��ԭʼ��ʯ", GOSSIP_SENDER_MAIN, 10);
	player->ADD_GOSSIP_ITEM(GOSSIP_ICON_INTERACT_2, "�ɿ�-> ����5��ԭʼ��ʯ", GOSSIP_SENDER_MAIN, 11);

	player->ADD_GOSSIP_ITEM(GOSSIP_ICON_INTERACT_2, "����-> ����5��ԭʼ��ʯ", GOSSIP_SENDER_MAIN, 12);
	player->ADD_GOSSIP_ITEM(GOSSIP_ICON_INTERACT_2, "����-> ����5��ԭʼ��ʯ", GOSSIP_SENDER_MAIN, 13);
	player->ADD_GOSSIP_ITEM(GOSSIP_ICON_INTERACT_2, "���-> ����5��ԭʼ��ʯ", GOSSIP_SENDER_MAIN, 14);;

	player->SEND_GOSSIP_MENU(player->GetGossipTextId(creature), creature->GetGUID());
	return true;
}
void CompleteLearnProfession(Player* pPlayer, Creature* pCreature, SkillType skill)
{
	if (pPlayer->GetFreePrimaryProfessionPoints() == 0 && !(skill == SKILL_COOKING || skill == SKILL_FIRST_AID))
	{
		pPlayer->GetSession()->SendNotification("���Ѿ�ѧ��������רҵ����.");
	}
	else
	{
		if (!LearnAllRecipesInProfession(pPlayer, skill))
			pPlayer->GetSession()->SendNotification("δ֪����.");
	}
}
bool GossipSelect_ProfessionNPC(Player* player, Creature* creature, uint32 sender, uint32 action)
{
	switch (action)
	{
	case 1:
		if (player->HasItemCount(42053, 5))
		{
			if (!player->HasSkill(SKILL_ALCHEMY))
				player->DestroyItemCount(42053, 5, true, false);
				CompleteLearnProfession(player, creature, SKILL_ALCHEMY);			
		}

		break;
	case 2:

		if (player->HasItemCount(42053, 5))
		{
			if (!player->HasSkill(SKILL_BLACKSMITHING))
				player->DestroyItemCount(42053, 5, true, false);
			CompleteLearnProfession(player, creature, SKILL_BLACKSMITHING);			
		}				
			
		break;

	case 3:

		if (player->HasItemCount(42053, 5))
		{
			if (!player->HasSkill(SKILL_LEATHERWORKING))
				player->DestroyItemCount(42053, 5, true, false);
			CompleteLearnProfession(player, creature, SKILL_LEATHERWORKING);
		}

		break;


	case 4:

		if (player->HasItemCount(42053, 5))
		{
			if (!player->HasSkill(SKILL_TAILORING))
				player->DestroyItemCount(42053, 5, true, false);
			CompleteLearnProfession(player, creature, SKILL_TAILORING);
		}

		break;


	case 5:

		if (player->HasItemCount(42053, 5))
		{
			if (!player->HasSkill(SKILL_ENGINEERING))
				player->DestroyItemCount(42053, 5, true, false);
			CompleteLearnProfession(player, creature, SKILL_ENGINEERING);
		}

		break;


	case 6:
		
		if (player->HasItemCount(42053, 5))
		{
			if (!player->HasSkill(SKILL_ENCHANTING))
				player->DestroyItemCount(42053, 5, true, false);
			CompleteLearnProfession(player, creature, SKILL_ENCHANTING);
		}

		break;



		
			
		
	case 7:
	case 8:
		break;
	case 9:

		if (player->HasItemCount(42053, 5))
		{
			if (!player->HasSkill(SKILL_HERBALISM))
				player->DestroyItemCount(42053, 5, true, false);
			CompleteLearnProfession(player, creature, SKILL_HERBALISM);
		}
				
			
		break;
	case 10:


		if (player->HasItemCount(42053, 5))
		{
			if (!player->HasSkill(SKILL_SKINNING))
				player->DestroyItemCount(42053, 5, true, false);
			CompleteLearnProfession(player, creature, SKILL_SKINNING);
		}


		break;

	case 11:

		if (player->HasItemCount(42053, 5))
		{
			if (!player->HasSkill(SKILL_MINING))
				player->DestroyItemCount(42053, 5, true, false);
			CompleteLearnProfession(player, creature, SKILL_MINING);
		}


		break;



	case 12:


		if (player->HasItemCount(42053, 5))
		{
			if (!player->HasSkill(SKILL_FIRST_AID))
				player->DestroyItemCount(42053, 5, true, false);
			CompleteLearnProfession(player, creature, SKILL_FIRST_AID);
		}


		break;


	case 13:


		if (player->HasItemCount(42053, 5))
		{
			if (!player->HasSkill(SKILL_FISHING))
				player->DestroyItemCount(42053, 5, true, false);
			CompleteLearnProfession(player, creature, SKILL_FISHING);
		}


		break;



	case 14:


		if (player->HasItemCount(42053, 5))
		{
			if (!player->HasSkill(SKILL_COOKING))
				player->DestroyItemCount(42053, 5, true, false);
			CompleteLearnProfession(player, creature, SKILL_COOKING);
		}


		break;



	}

	player->CLOSE_GOSSIP_MENU();
	return true;
}
//*****************************************

bool GossipHello_RaLNPC(Player* player, Creature* creature)
{
	char* tmp = new char[100];
	sprintf(tmp, "|cFF0041FF�ҵ��ʻ����֣�[%d]��|r ��", player->Getjifen());
	player->ADD_GOSSIP_ITEM(4, tmp, GOSSIP_SENDER_MAIN, 0);

	player->ADD_GOSSIP_ITEM(GOSSIP_ICON_INTERACT_2, "���������ű� -> ��Ҫ2��ԭʼ��ʯ", GOSSIP_SENDER_MAIN, 1);
	player->ADD_GOSSIP_ITEM(GOSSIP_ICON_INTERACT_2, "ֱ��60��     -> ��Ҫ5��ԭʼ��ʯ", GOSSIP_SENDER_MAIN, 2);
	player->ADD_GOSSIP_ITEM(GOSSIP_ICON_INTERACT_2, "���ֶһ�     -> ����1 : 100G   ", GOSSIP_SENDER_MAIN, 3);
	//player->ADD_GOSSIP_ITEM(GOSSIP_ICON_INTERACT_2, "��ȡ����     -> ������ʱ��һ� ", GOSSIP_SENDER_MAIN, 4);
	//player->ADD_GOSSIP_ITEM(GOSSIP_ICON_INTERACT_2, "����", GOSSIP_SENDER_MAIN, 5);
	//player->ADD_GOSSIP_ITEM(GOSSIP_ICON_INTERACT_2, "��ħ", GOSSIP_SENDER_MAIN, 6);
	////player->ADD_GOSSIP_ITEM(GOSSIP_ICON_INTERACT_2, "�鱦�ӹ�" , GOSSIP_SENDER_MAIN, 7);
	////player->ADD_GOSSIP_ITEM(GOSSIP_ICON_INTERACT_2, "����" , GOSSIP_SENDER_MAIN, 8);
	//player->ADD_GOSSIP_ITEM(GOSSIP_ICON_INTERACT_2, "��ҩ", GOSSIP_SENDER_MAIN, 9);
	//player->ADD_GOSSIP_ITEM(GOSSIP_ICON_INTERACT_2, "��Ƥ", GOSSIP_SENDER_MAIN, 10);
	//player->ADD_GOSSIP_ITEM(GOSSIP_ICON_INTERACT_2, "�ɿ�", GOSSIP_SENDER_MAIN, 11);

	//player->ADD_GOSSIP_ITEM(GOSSIP_ICON_INTERACT_2, "����", GOSSIP_SENDER_MAIN, 12);
	//player->ADD_GOSSIP_ITEM(GOSSIP_ICON_INTERACT_2, "����", GOSSIP_SENDER_MAIN, 13);
	//player->ADD_GOSSIP_ITEM(GOSSIP_ICON_INTERACT_2, "���", GOSSIP_SENDER_MAIN, 14);;

	player->SEND_GOSSIP_MENU(player->GetGossipTextId(creature), creature->GetGUID());
	return true;
}
void CompleteLearnProfessionTodo(Player* pPlayer, Creature* pCreature, SkillType skill)
{
	if (pPlayer->GetFreePrimaryProfessionPoints() == 0 && !(skill == SKILL_COOKING || skill == SKILL_FIRST_AID))
	{
		pPlayer->GetSession()->SendNotification("���Ѿ�ѧ��������רҵ����.");
	}
	else
	{
		if (!LearnAllRecipesInProfession(pPlayer, skill))
			pPlayer->GetSession()->SendNotification("δ֪����.");
	}
}
bool GossipSelect_RaLNPC(Player* player, Creature* creature, uint32 sender, uint32 action)
{
	int JF = 0;
	switch (action)
	{
	case 1:
		

		if (player->HasItemCount(42053, 1)) // �޸�һ��152���޸ĳ�����Ҫ�������ĵ���ƷID
		{
			player->DestroyItemCount(42053, 1, true, true); // name change token (1552) you can change it
			player->DestroyItemCount(42053, 1, true, false); // name change token (1552) you can change it
			//player->SetAtLoginFlag(AT_LOGIN_RENAME);
			//CharacterDatabase.PExecute("UPDATE characters SET money=money+1000 | '8' WHERE guid = %u", player->GetGUID());

			//CharacterDatabase.PExecute("delete from `instance` where `id` in(select `instance` from `group_instance` where `leaderGuid`='%u');", player->GetGUIDLow());
			//CharacterDatabase.PExecute("delete from `group_instance` where `leaderGuid`='%u';", player->GetGUIDLow());
			CharacterDatabase.PExecute("delete from `character_instance` where `guid`='%u';", player->GetGUIDLow());
			CharacterDatabase.CommitTransaction();

			player->GetSession()->SendNotification("�����Ѿ����ã���Ҫ���µ�¼��Ϸ����Ч!");
			//player->PlayerTalkClass->CloseGossip();
			//player->ModifyMoney(100000);
			//player->UnbindInstance(409, FALSE);
			//player->GetSession()->SendNotification()
			
		}
		else
		{
			player->GetSession()->SendNotification("��������Ҫ2��ԭʼ��ʯ��");
			player->PlayerTalkClass->CloseGossip();
		}

		

		break;
	case 2:
		
		if (player->HasItemCount(42053, 5))
		{ 
		   if (player->GetLevel() >= 60)
		  {
			player->GetSession()->SendNotification("�㲻������ߵȼ���");
			return false;
		   }
		else
		   {
			//player->GiveLevel(player->GetLevel() + 1);	
			player->GiveXP(4084700, player);
			player->DestroyItemCount(42053, 5, true, false);
			player->GetSession()->SendNotification("�����ȼ��ɹ�");
			return true;
		    }
		}
		else
		{
			player->GetSession()->SendNotification("��������Ҫ5��ԭʼ��ʯ��");
			player->PlayerTalkClass->CloseGossip();
		}



		break;
	case 3:

		JF = player->Getjifen();
		if (JF > 0)
		{
			//player->AddItem(42053, JF);
			player->ModifyMoney(1000000 * JF);
			player->Modifyjifen(-JF);
			player->GetSession()->SendNotification("|cffFFFF00WOW ��Ʒ�Ѿ�����,��鿴����!");

		}

		else
		{

			player->GetSession()->SendNotification("|cffFFFF00WOW ���ֲ���! ϵͳ��������");
			return 0;
		}
		break;
	case 4:
		

		break;
	case 5:
		if (!player->HasSkill(SKILL_ENGINEERING))
			CompleteLearnProfession(player, creature, SKILL_ENGINEERING);
		break;
	case 6:
		if (!player->HasSkill(SKILL_ENCHANTING))
			CompleteLearnProfession(player, creature, SKILL_ENCHANTING);
		break;
	case 7:
	case 8:
		break;
	case 9:
		if (!player->HasSkill(SKILL_HERBALISM))
			CompleteLearnProfession(player, creature, SKILL_HERBALISM);
		break;
	case 10:
		if (!player->HasSkill(SKILL_SKINNING))
			CompleteLearnProfession(player, creature, SKILL_SKINNING);
		break;
	case 11:
		if (!player->HasSkill(SKILL_MINING))
			CompleteLearnProfession(player, creature, SKILL_MINING);
		break;
	case 12:
		if (!player->HasSkill(SKILL_FIRST_AID))
			CompleteLearnProfession(player, creature, SKILL_FIRST_AID);
		break;
	case 13:
		if (!player->HasSkill(SKILL_FISHING))
			CompleteLearnProfession(player, creature, SKILL_FISHING);
		break;
	case 14:
		if (!player->HasSkill(SKILL_COOKING))
			CompleteLearnProfession(player, creature, SKILL_COOKING);
		break;
	}

	player->CLOSE_GOSSIP_MENU();
	return true;
}
















//************************************************************


/*
* Custom premade gear and spec scripts
*/

#define SPELL_LIGHTNING_VISUAL 24240

bool GossipHello_PremadeGearNPC(Player* player, Creature* creature)
{
	for (auto itr : sObjectMgr.GetPlayerPremadeGearTemplates())
	{
		if (itr.second.requiredClass == player->GetClass())
		{
			player->ADD_GOSSIP_ITEM(GOSSIP_ICON_INTERACT_2, itr.second.name.c_str(), GOSSIP_SENDER_MAIN, itr.first);
		}
	}

	player->SEND_GOSSIP_MENU(player->GetGossipTextId(creature), creature->GetGUID());
	return true;
}

bool GossipSelect_PremadeGearNPC(Player* player, Creature* creature, uint32 sender, uint32 action)
{
	player->SendSpellGo(player, SPELL_LIGHTNING_VISUAL);
	sObjectMgr.ApplyPremadeGearTemplateToPlayer(action, player);
	player->CLOSE_GOSSIP_MENU();
	return true;
}

bool GossipHello_PremadeSpecNPC(Player* player, Creature* creature)
{
	for (auto itr : sObjectMgr.GetPlayerPremadeSpecTemplates())
	{
		if (itr.second.requiredClass == player->GetClass())
		{
			player->ADD_GOSSIP_ITEM(GOSSIP_ICON_INTERACT_2, itr.second.name.c_str(), GOSSIP_SENDER_MAIN, itr.first);
		}
	}

	player->SEND_GOSSIP_MENU(player->GetGossipTextId(creature), creature->GetGUID());
	return true;
}

bool GossipSelect_PremadeSpecNPC(Player* player, Creature* creature, uint32 sender, uint32 action)
{
	player->SendSpellGo(player, SPELL_LIGHTNING_VISUAL);
	sObjectMgr.ApplyPremadeSpecTemplateToPlayer(action, player);
	player->CLOSE_GOSSIP_MENU();
	return true;
}

/*
* Custom training dummy script
*/

struct npc_training_dummyAI : ScriptedAI
{
	explicit npc_training_dummyAI(Creature* pCreature) : ScriptedAI(pCreature)
	{
		npc_training_dummyAI::Reset();
	}

	uint32 m_uiCombatTimer;
	std::unordered_map<ObjectGuid, time_t> attackers;

	void Reset() override
	{
		m_uiCombatTimer = 15000;
		attackers.clear();
	}

	void AttackStart(Unit* /*pWho*/) override {}

	void Aggro(Unit* pWho) override
	{
		SetCombatMovement(false);
	}

	void AddAttackerToList(Unit* pWho)
	{
		auto itr = attackers.find(pWho->GetObjectGuid());
		if (itr != attackers.end())
		{
			itr->second = std::time(nullptr);
		}
		else
		{
			attackers.emplace(pWho->GetObjectGuid(), std::time(nullptr));
		}
	}

	void DamageTaken(Unit* pWho, uint32& /*uiDamage*/) override
	{
		if (pWho)
			AddAttackerToList(pWho);
	}

	void SpellHit(Unit* pWho, SpellEntry const* /*pSpell*/) override
	{
		if (pWho)
			AddAttackerToList(pWho);
	}

	void UpdateAI(uint32 const diff) override
	{
		if (m_creature->IsInCombat())
		{
			if (m_uiCombatTimer <= diff)
			{
				for (auto itr = attackers.begin(); itr != attackers.end();)
				{
					Unit* pAttacker = m_creature->GetMap()->GetUnit(itr->first);

					if (!pAttacker || !pAttacker->IsInWorld())
					{
						itr = attackers.erase(itr);
						continue;
					}
					if (itr->second + 10 < std::time(nullptr))
					{
						m_creature->_removeAttacker(pAttacker);
						m_creature->GetThreatManager().modifyThreatPercent(pAttacker, -101.0f);
						itr = attackers.erase(itr);
						continue;
					}
					++itr;
				}

				if (m_creature->GetThreatManager().isThreatListEmpty())
					EnterEvadeMode();

				m_uiCombatTimer = 15000;
			}
			else
				m_uiCombatTimer -= diff;
		}
	}
};

CreatureAI* GetAI_npc_training_dummy(Creature* pCreature)
{
	return new npc_training_dummyAI(pCreature);
}

struct npc_summon_debugAI : ScriptedAI
{
	uint32 m_maxSummonCount = 200;
	uint32 m_summonCount = 0;
	Creature* m_summons[200];

	npc_summon_debugAI(Creature* pCreature) : ScriptedAI(pCreature)
	{
		m_summonCount = 0;
		for (uint32 i = 0; i < m_maxSummonCount; ++i)
			m_summons[i] = nullptr;

		Reset();
	}

	void Reset() override
	{
		m_summonCount = 0;
		for (uint32 i = 0; i < m_maxSummonCount; ++i)
		{
			if (m_summons[i])
				((TemporarySummon*)m_summons[i])->UnSummon();

			m_summons[i] = nullptr;
		}
	}


	void JustDied(Unit* /* killer */) override
	{
		Reset();
	}

	void UpdateAI(uint32 const diff) override
	{
		if (!m_creature->GetVictim())
			return;

		if (m_summonCount >= m_maxSummonCount)
			return;

		m_summons[m_summonCount++] = m_creature->SummonCreature(12458, m_creature->GetPositionX(), m_creature->GetPositionY(), m_creature->GetPositionZ(), 0);
	}
};

CreatureAI* GetAI_custom_summon_debug(Creature* creature)
{
	return new npc_summon_debugAI(creature);
}

//
//bool GossipHello_CZ_NPC(Player* player, Creature* creature)
//{
//	char* tmp = new char[100];
//	sprintf(tmp, "|cFF0041FF����ע��!����ѡ���������װ�����ж�Ӧ��װ��,���ɳ���,��ע��!|r ", 0);
//	player->ADD_GOSSIP_ITEM(4, tmp, GOSSIP_SENDER_MAIN, 0);
//
//	//player->ADD_GOSSIP_ITEM(5, "�ز�", GOSSIP_SENDER_MAIN, EQUIPMENT_SLOT_CHEST);
//	//player->ADD_GOSSIP_ITEM(5, "����", GOSSIP_SENDER_MAIN, EQUIPMENT_SLOT_BACK);
//	//player->ADD_GOSSIP_ITEM(5, "����", GOSSIP_SENDER_MAIN, EQUIPMENT_SLOT_WRISTS);
//	//player->ADD_GOSSIP_ITEM(5, "����", GOSSIP_SENDER_MAIN, EQUIPMENT_SLOT_HANDS);
//	//player->ADD_GOSSIP_ITEM(5, "ѥ��", GOSSIP_SENDER_MAIN, EQUIPMENT_SLOT_FEET);
//	player->ADD_GOSSIP_ITEM(5, "��������װ��-> ����1ԭʼ��ʯ", GOSSIP_SENDER_MAIN, EQUIPMENT_SLOT_MAINHAND);
//	player->ADD_GOSSIP_ITEM(5, "���ø���װ��-> ����1ԭʼ��ʯ", GOSSIP_SENDER_MAIN, EQUIPMENT_SLOT_OFFHAND);
//
//	player->SEND_GOSSIP_MENU(player->GetGossipTextId(creature), creature->GetGUID());
//	return true;
//}
//bool GossipSelect_CZ_NPC(Player* player, Creature* creature, uint32 sender, uint32 action)
//{
//
//	if (sender != GOSSIP_SENDER_MAIN)
//		return true;
//
//	if (action < 20)
//	{
//		switch (action)
//		{
//		case EQUIPMENT_SLOT_CHEST:
//			player->ADD_GOSSIP_ITEM(5, "��������+4", GOSSIP_SENDER_MAIN, CHEST_STATS);
//			break;
//		case EQUIPMENT_SLOT_BACK:
//			player->ADD_GOSSIP_ITEM(5, "����+3", GOSSIP_SENDER_MAIN, CLOAK_AGILITY);
//			player->ADD_GOSSIP_ITEM(5, "����+70", GOSSIP_SENDER_MAIN, CLOAK_ARMOR);
//			player->ADD_GOSSIP_ITEM(5, "����+1%", GOSSIP_SENDER_MAIN, CLOAK_DODGE);
//			player->ADD_GOSSIP_ITEM(5, "��թ", GOSSIP_SENDER_MAIN, CLOAK_SUB);
//			break;
//		case EQUIPMENT_SLOT_WRISTS:
//			player->ADD_GOSSIP_ITEM(5, "����+9", GOSSIP_SENDER_MAIN, BRACER_STAM);
//			player->ADD_GOSSIP_ITEM(5, "����+9", GOSSIP_SENDER_MAIN, BRACER_STR);
//			player->ADD_GOSSIP_ITEM(5, "���Ʒ���+24", GOSSIP_SENDER_MAIN, BRACER_HEAL);
//			player->ADD_GOSSIP_ITEM(5, "����+7", GOSSIP_SENDER_MAIN, BRACER_INT);
//			break;
//		case EQUIPMENT_SLOT_HANDS:
//			player->ADD_GOSSIP_ITEM(5, "����+15", GOSSIP_SENDER_MAIN, GLOVES_AGI);
//			player->ADD_GOSSIP_ITEM(5, "�����˺�+20", GOSSIP_SENDER_MAIN, GLOVES_FIRE);
//			player->ADD_GOSSIP_ITEM(5, "��˪�˺�+20", GOSSIP_SENDER_MAIN, GLOVES_FROST);
//			player->ADD_GOSSIP_ITEM(5, "��Ӱ�˺�+20", GOSSIP_SENDER_MAIN, GLOVES_SHADOW);
//			player->ADD_GOSSIP_ITEM(5, "���Ʒ���+30", GOSSIP_SENDER_MAIN, GLOVES_HEALING);
//			break;
//		case EQUIPMENT_SLOT_FEET:
//			player->ADD_GOSSIP_ITEM(5, "����+7", GOSSIP_SENDER_MAIN, BOOTS_STAM);
//			player->ADD_GOSSIP_ITEM(5, "�ƶ��ٶ�", GOSSIP_SENDER_MAIN, BOOTS_SPEED);
//			player->ADD_GOSSIP_ITEM(5, "����+5", GOSSIP_SENDER_MAIN, BOOTS_AGI);
//			break;
//		case EQUIPMENT_SLOT_MAINHAND:
//
//
//			player->ADD_GOSSIP_ITEM(5, "ʮ�־�", GOSSIP_SENDER_MAIN, WEP_CRUSADER);
//			player->ADD_GOSSIP_ITEM(5, "15����", GOSSIP_SENDER_MAIN, WEP1H_AGILITY);
//			player->ADD_GOSSIP_ITEM(5, "25����", GOSSIP_SENDER_MAIN, WEP2H_AGILITY);
//			player->ADD_GOSSIP_ITEM(5, "�����˺�+30", GOSSIP_SENDER_MAIN, WEP_SPELLPOWER);
//			player->ADD_GOSSIP_ITEM(5, "���Ʒ���+55", GOSSIP_SENDER_MAIN, WEP_HEAL);
//			break;
//		case EQUIPMENT_SLOT_OFFHAND:
//			player->ADD_GOSSIP_ITEM(5, "����+9", GOSSIP_SENDER_MAIN, OFFHAND_SPIRIT);
//			player->ADD_GOSSIP_ITEM(5, "����+7", GOSSIP_SENDER_MAIN, OFFHAND_STAM);
//			player->ADD_GOSSIP_ITEM(5, "��˪����+8", GOSSIP_SENDER_MAIN, OFFHAND_FROSTRES);
//			break;
//		}
//		player->SEND_GOSSIP_MENU(DEFAULT_GOSSIP_MESSAGE, creature->GetGUID());
//	}
//	else
//	{
//		Item* item = nullptr;
//		uint32 id = 0;
//		switch (action)
//		{
//		case WEP2H_SUPERIOR_IMPACT:
//		case WEP2H_AGILITY:
//			item = player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_MAINHAND);
//			if (item && (action == WEP2H_AGILITY || action == WEP2H_SUPERIOR_IMPACT))
//			{
//				if (item->GetProto()->SubClass != ITEM_SUBCLASS_WEAPON_AXE2 && item->GetProto()->SubClass != ITEM_SUBCLASS_WEAPON_MACE2
//					&& item->GetProto()->SubClass != ITEM_SUBCLASS_WEAPON_SWORD2 && item->GetProto()->SubClass != ITEM_SUBCLASS_WEAPON_POLEARM
//					&& item->GetProto()->SubClass != ITEM_SUBCLASS_WEAPON_STAFF)
//				{
//					player->GetSession()->SendNotification("��Ҫ��װ��˫������");
//					player->CLOSE_GOSSIP_MENU();
//					return true;
//				}
//			}
//			if (action == WEP2H_SUPERIOR_IMPACT)
//				id = 1896;
//			else if (action == WEP2H_AGILITY)
//				id = 2646;
//			break;
//
//		case WEP_CRUSADER:
//			item = player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_MAINHAND);
//			id = 1900;
//			break;
//		case WEP1H_AGILITY:
//			item = player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_MAINHAND);
//			id = 2564;
//			break;
//		case WEP_SPELLPOWER:
//			item = player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_MAINHAND);
//			id = 2504;
//			break;
//		case WEP_HEAL:
//			item = player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_MAINHAND);
//			id = 2505;
//			break;
//
//		case OFFHAND_SPIRIT:
//		case OFFHAND_STAM:
//		case OFFHAND_FROSTRES:
//			item = player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_OFFHAND);
//			if (item && item->GetProto()->SubClass != ITEM_SUBCLASS_ARMOR_SHIELD)
//			{
//				player->GetSession()->SendNotification("����Ҫ��װ������");
//				player->CLOSE_GOSSIP_MENU();
//				return true;
//			}
//			if (action == OFFHAND_SPIRIT)
//				id = 1890;
//			else if (action == OFFHAND_FROSTRES)
//				id = 926;
//			else if (action == OFFHAND_STAM)
//				id = 929;
//			break;
//		case CHEST_STATS:
//			item = player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_CHEST);
//			id = 1891;
//			break;
//		case CLOAK_DODGE:
//			item = player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_BACK);
//			id = 2622;
//			break;
//		case CLOAK_SUB:
//			item = player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_BACK);
//			id = 2621;
//			break;
//		case CLOAK_ARMOR:
//			item = player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_BACK);
//			id = 1889;
//			break;
//		case CLOAK_AGILITY:
//			item = player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_BACK);
//			id = 849;
//			break;
//		case BRACER_STAM:
//			item = player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_WRISTS);
//			id = 1886;
//			break;
//		case BRACER_STR:
//			item = player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_WRISTS);
//			id = 1885;
//			break;
//		case BRACER_HEAL:
//			item = player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_WRISTS);
//			id = 2566;
//			break;
//		case BRACER_INT:
//			item = player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_WRISTS);
//			id = 1883;
//			break;
//		case GLOVES_AGI:
//			item = player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_HANDS);
//			id = 2564;
//			break;
//		case GLOVES_FIRE:
//			item = player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_HANDS);
//			id = 2616;
//			break;
//		case GLOVES_FROST:
//			item = player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_HANDS);
//			id = 2615;
//			break;
//		case GLOVES_SHADOW:
//			item = player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_HANDS);
//			id = 2614;
//			break;
//		case GLOVES_HEALING:
//			item = player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_HANDS);
//			id = 2617;
//			break;
//		case BOOTS_AGI:
//			item = player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_FEET);
//			id = 904;
//			break;
//		case BOOTS_SPEED:
//			item = player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_FEET);
//			id = 911;
//			break;
//		case BOOTS_STAM:
//			item = player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_FEET);
//			id = 929;
//			break;
//		}
//
//
//
//		Enchant(player, item, id);
//		player->CLOSE_GOSSIP_MENU();
//	}
//	return true;
//}
//





void AddSC_custom_creatures()
{
	Script* newscript;

	newscript = new Script;
	newscript->Name = "custom_teleport_npc";
	newscript->pGossipHello = &GossipHello_TeleportNPC;
	newscript->pGossipSelect = &GossipSelect_TeleportNPC;
	newscript->RegisterSelf(false);

	newscript = new Script;
	newscript->Name = "custom_enchant_npc";
	newscript->pGossipHello = &GossipHello_EnchantNPC;
	newscript->pGossipSelect = &GossipSelect_EnchantNPC;
	newscript->RegisterSelf(false);

	newscript = new Script;
	newscript->Name = "custom_enchantCZ_npc";
	newscript->pGossipHello = &GossipHello_EnchantCZNPC;
	newscript->pGossipSelect = &GossipSelect_EnchantCZNPC;
	newscript->RegisterSelf(false);



	newscript = new Script;
	newscript->Name = "custom_professions_npc";
	newscript->pGossipHello = &GossipHello_ProfessionNPC;
	newscript->pGossipSelect = &GossipSelect_ProfessionNPC;
	newscript->RegisterSelf(false);

	newscript = new Script;
	newscript->Name = "custom_premade_gear_npc";
	newscript->pGossipHello = &GossipHello_PremadeGearNPC;
	newscript->pGossipSelect = &GossipSelect_PremadeGearNPC;
	newscript->RegisterSelf(false);

	newscript = new Script;
	newscript->Name = "custom_premade_spec_npc";
	newscript->pGossipHello = &GossipHello_PremadeSpecNPC;
	newscript->pGossipSelect = &GossipSelect_PremadeSpecNPC;
	newscript->RegisterSelf(false);

	newscript = new Script;
	newscript->Name = "custom_npc_training_dummy";
	newscript->GetAI = &GetAI_npc_training_dummy;
	newscript->RegisterSelf(false);

	newscript = new Script;
	newscript->Name = "custom_npc_summon_debugAI";
	newscript->GetAI = &GetAI_custom_summon_debug;
	newscript->RegisterSelf(false);


	newscript = new Script;
	newscript->Name = "custom_Select_RaLNPC_npc";
	newscript->pGossipHello = &GossipHello_RaLNPC;
	newscript->pGossipSelect = &GossipSelect_RaLNPC;
	newscript->RegisterSelf(false);






}
