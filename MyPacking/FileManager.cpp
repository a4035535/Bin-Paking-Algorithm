#include "FileManager.h"
#include "fstream"
#include "sstream"
#include "string"

CString FileManager::GetFilePath() {
	OPENFILENAME ofn;// �����Ի���ṹ
	char szFile[300];// ���������ȡ�ļ����ƵĻ�����

	ZeroMemory(&ofn, sizeof(ofn));// ��ʼ��ѡ���ļ��Ի���
	ofn.lStructSize = sizeof(ofn);//ָ������ṹ�Ĵ�С�����ֽ�Ϊ��λ
	ofn.hwndOwner = NULL;
	ofn.lpstrFile = (LPSTR)szFile;//�򿪵��ļ���ȫ·��
	ofn.lpstrFile[0] = '\0';//��һ���ַ����ǹ�������������ʾ�ַ���
	LPTSTR        lpstrCustomFilter;
	DWORD         nMaxCustFilter;
	ofn.nFilterIndex = 1;
	LPTSTR        lpstrFile;
	ofn.nMaxFile = sizeof(szFile);
	//ofn.lpstrFilter = (LPSTR)"ALL\0*.*\0Text\0*.TXT\0";//��������
	ofn.lpstrFilter = (LPSTR)"0Text\0*.TXT\0";
	ofn.lpstrFileTitle = NULL;
	ofn.nMaxFileTitle = 0;
	ofn.lpstrInitialDir = (LPCSTR)"F:\\WorkSpace\\VisualStudio\\MyPacking\\MyPacking";
	ofn.Flags = OFN_PATHMUSTEXIST | OFN_FILEMUSTEXIST;

	CString filePath;
	if (GetOpenFileName(&ofn)) {
		//path_image = Lpcwstr2String((LPCWSTR)ofn.lpstrFile);//��һ��LPCWSTRת��Ϊstring
		filePath.Format("%s", ofn.lpstrFile);
		return filePath;
	}
	else {
		return "";
	}
}

vector<vector<int>> FileManager::GetFileIntData(CString path)
{
	ifstream data(path);
	vector<vector<int>>res;
	string line;
	while (getline(data, line))
	{
		stringstream ss;//������
		ss << line;
		if (!ss.eof()) 
		{
			int temp;
			vector<int>blockInfo;
			while (ss >> temp)
				blockInfo.push_back(temp);
			res.push_back(blockInfo);
		}
	}
	return res;
}