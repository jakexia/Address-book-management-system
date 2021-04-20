#include <iostream>
using namespace std;
#include <string>
#define MAX 1000

//�����ϵ�˽ṹ��
struct Person
{
	//����
	string m_Name;
	//�Ա� 1 �� 2 Ů
	int m_Sex;
	//����
	int m_Age;
	//�绰
	string m_Phone;
	//סַ
	string m_Addr;
};

//���ͨѶ¼�ṹ��
struct Addressbooks
{
	//ͨѶ¼�б������ϵ�˵�����
	struct Person personArray[MAX];

	//ͨѶ¼�е�ǰ��¼����ϵ�˸���
	int m_Size;
};

//1�������ϵ��
void addPerson(Addressbooks* abs)
{
	//���ж�ͨѶ¼�Ƿ�������������˾Ͳ������
	if (abs->m_Size == MAX)
	{
		cout << "ͨѶ¼�������޷���ӣ�" << endl;
		return;
	}
	else
	{
		//��Ӿ������ϵ��

		//����
		string name;
		cout << "������������  " << endl;
		cin >> name;
		abs->personArray[abs->m_Size].m_Name = name;

		//�Ա�
		cout << "�������Ա�  " << endl;
		cout << "1 --- ��" << endl;
		cout << "2 --- Ů" << endl;

		int sex = 0;
		
		while (true)
		{
			//�������1��2�����˳�ѭ������Ϊ���������ȷֵ
			//���������������������
			cin >> sex;
			if (sex == 1 || sex == 2)
			{
				abs->personArray[abs->m_Size].m_Sex = sex;
				break;
			}
			cout << "������������������" << endl;
		}

		//����
		cout << "���������䣺  " << endl;
		int age = 0;

		while (true)
		{
			cin >> age;
			if (age >= 0 && age <= 150)
			{
				abs->personArray[abs->m_Size].m_Age = age;
				break;
			}
			cout << "��������ȷ������" << endl;
		}

		//�绰
		cout << "������绰��  " << endl;
		string phone;
		cin >> phone;
		abs->personArray[abs->m_Size].m_Phone = phone;

		//סַ
		cout << "�������ͥסַ��  " << endl;
		string address;
		cin >> address;
		abs->personArray[abs->m_Size].m_Addr = address;

		//����ͨѶ¼�е�����
		abs->m_Size++;

		cout << "��ӳɹ�" << endl;

		system("pause"); //�����������
		system("cls"); //�����Ļ
	}
}

//2����ʾ���е���ϵ��
void showPerson(Addressbooks * abs)
{
	//�ж�ͨѶ¼�������Ƿ�Ϊ0�����Ϊ0����ʾ��¼Ϊ��
	//�����Ϊ0����ʾ��¼����ϵ����Ϣ
	if (abs->m_Size == 0)
	{
		cout << "��ǰ�ļ�¼Ϊ��" << endl;
	}
	else
	{
		for (int i = 0; i < abs->m_Size; i++)
		{
			cout << "������  " << abs->personArray[i].m_Name << "\t";
			cout << "�Ա�  " << (abs->personArray[i].m_Sex == 1 ? "��" : "Ů") << "\t";
			cout << "���䣺  " << abs->personArray[i].m_Age << "\t";
			cout << "�绰��  " << abs->personArray[i].m_Phone << "\t";
			cout << "סַ��  " << abs->personArray[i].m_Addr << endl;
		}
	}

	system("pause");
	system("cls");
}

//�����ϵ���Ƿ���ڣ�������ڣ�������ϵ�����������еľ���λ�ã������ڷ���-1
int isExist(Addressbooks * abs, string name)
{
	for (int i = 0; i < abs->m_Size; i++)
	{
		//�ҵ��û����������
		if (name == abs->personArray[i].m_Name)
		{
			return i; //�ҵ��˷��ظ����������е��±���
		}
	}
	return -1; //����������û���ҵ�������-1
}

//3��ɾ��ָ������ϵ��
void deletePerson(Addressbooks * abs)
{
	cout << "��������Ҫɾ������ϵ�ˣ�  " << endl;

	string name;
	cin >> name;

	int ret = isExist(abs, name);

	if (ret != -1)
	{
		//���ҵ��ˣ�Ҫ����ɾ������
		for (int i = ret; i < abs->m_Size; i++)
		{
			//����ǰ��
			abs->personArray[i] = abs->personArray[i + 1];
		}
		abs->m_Size--; //����ͨѶ¼�е���Ա��
		cout << "ɾ���ɹ�" << endl;
	}
	else
	{
		cout << "���޴���" << endl;
	}

	system("pause");
	system("cls");
}

//4������ָ������ϵ����Ϣ
void findPerson(Addressbooks* abs)
{
	cout << "������Ҫ���ҵ���ϵ�ˣ�  " << endl;
	string name;
	cin >> name;

	int ret = isExist(abs, name);
	if (ret != -1)
	{
		cout << "������  " << abs->personArray[ret].m_Name << "\t";
		cout << "�Ա�  " << (abs->personArray[ret].m_Sex == 1 ? "��" : "Ů") << "\t";
		cout << "���䣺  " << abs->personArray[ret].m_Age << "\t";
		cout << "�绰��  " << abs->personArray[ret].m_Phone << "\t";
		cout << "סַ��  " << abs->personArray[ret].m_Addr << endl;
	}
	else
	{
		cout << "���޴���" << endl;
	}

	system("pause");
	system("cls");
}

//5���޸�ָ������ϵ����Ϣ
void modifyPerson(Addressbooks * abs)
{
	cout << "������Ҫ�޸ĵ���ϵ��" << endl;
	string name;
	cin >> name;

	int ret = isExist(abs, name);
	if (ret != -1)
	{
		cout << "*******************" << endl;
		cout << "**  1���޸�����  **" << endl;
		cout << "**  2���޸��Ա�  **" << endl;
		cout << "**  3���޸�����  **" << endl;
		cout << "**  4���޸ĵ绰  **" << endl;
		cout << "**  5���޸�סַ  **" << endl;
		cout << "**  6���˳��޸�  **" << endl;
		cout << "*******************" << endl;

		int select = 0;
		cin >> select;

		switch (select)
		{
		case 1://����
		{
			string modifyname;
			cout << "������������  " << endl;
			cin >> modifyname;
			abs->personArray[ret].m_Name = modifyname;
			cout << "�޸������ɹ�" << endl;
		}
		break;
		case 2://�Ա�
		{
			int modifysex = 0;
			cout << "�������Ա�  " << endl;
			cout << "1 --- ��" << endl;
			cout << "2 --- Ů" << endl;

			while (true)
			{
				cin >> modifysex;
				if (modifysex == 1 || modifysex == 2)
				{
					abs->personArray[ret].m_Sex = modifysex;
					cout << "�޸��Ա�ɹ�" << endl;
					break;
				}
				cout << "������������������" << endl;
			}
		}
		break;
		case 3://����
		{
			int modifyage = 0;
			cout << "���������䣺  " << endl;
			while (true)
			{
				cin >> modifyage;
				if (modifyage >= 0 && modifyage <= 150)
				{
					abs->personArray[ret].m_Age = modifyage;
					cout << "�޸�����ɹ�" << endl;
					break;
				}
				cout << "������������������" << endl;
			}
		}
		break;
		case 4://�绰
		{
			string modifyphone;
			cout << "������绰��  " << endl;
			cin >> modifyphone;
			abs->personArray[ret].m_Phone = modifyphone;
			cout << "�޸ĵ绰�ɹ�" << endl;
		}
		break;
		case 5://סַ
		{
			string modifyaddr;
			cout << "������סַ��  " << endl;
			cin >> modifyaddr;
			abs->personArray[ret].m_Addr = modifyaddr;
			cout << "�޸�סַ�ɹ�" << endl;
		}
		break;
		default:
			cout << "�������ʾ��ȷ����" << endl;
			break;
		}
	}
	else
	{
		cout << "���޴���" << endl;
	}

	system("pause");
	system("cls");
}

//6�������ϵ��
void cleanPerson(Addressbooks* abs)
{
	cout << "���Ƿ����Ҫ��գ�" << endl;
	cout << "1 --- ��" << endl;
	cout << "2 --- ��" << endl;
	int clear = 0;

	while(true)
	{
		cin >> clear;
		if (clear == 1 || clear == 2)
		{
			if(clear == 1)
			{
				abs->m_Size = 0;
				cout << "ͨѶ¼�����" << endl;
				break;
			}
			else
			{
				cout << "��Ϣ������" << endl;
				break;
			}
		}
		else
		{
			cout << "�����������������" << endl;
		}
	}

	system("pause");
	system("cls");
}

//�˵�����
void showMenu()
{
	cout << "***************************" << endl;
	cout << "*****  1�������ϵ��  *****" << endl;
	cout << "*****  2����ʾ��ϵ��  *****" << endl;
	cout << "*****  3��ɾ����ϵ��  *****" << endl;
	cout << "*****  4��������ϵ��  *****" << endl;
	cout << "*****  5���޸���ϵ��  *****" << endl;
	cout << "*****  6�������ϵ��  *****" << endl;
	cout << "*****  0���˳���ϵ��  *****" << endl;
	cout << "***************************" << endl;
}

int main()
{
	//����ͨѶ¼�ṹ�����
	Addressbooks abs;
	//��ʼ��ͨѶ¼�е�ǰ��Ա����
	abs.m_Size = 0;
	int select = 0; //�����û�ѡ������ı���
	
	while (true)
	{
		//�˵�����
		showMenu();

		cin >> select;

		switch (select)
		{
		case 1://�����ϵ��
			addPerson(&abs); //���õ�ַ���ݣ���������ʵ��
			break;
		case 2://��ʾ��ϵ��
			showPerson(&abs);
			break;
		case 3://ɾ����ϵ��
			deletePerson(&abs);
			break;
		case 4://������ϵ��
			findPerson(&abs);
			break;
		case 5://�޸���ϵ��
			modifyPerson(&abs);
			break;
		case 6://�����ϵ��
			cleanPerson(&abs);
			break;
		case 0://�˳���ϵ��
			cout << "��ӭ�´�ʹ��" << endl;
			system("pause");
			return 0;
			break;
		default:
			cout << "�밴����ʾ����" << endl;
			break;
		}
	}
	system("pause");

	return 0;
}