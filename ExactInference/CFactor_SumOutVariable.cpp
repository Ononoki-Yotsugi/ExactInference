/////////////////////////////////////////////////////////////////////////////////////////////
//�ļ�����		CFactor_SumOutVariable.cpp
//��  �ܣ�		���ݸ������������������
//�����ߣ�		��־ǿ
//��  �ڣ�		2021��03��13��
//��  �£�		2021��03��23��
//��  �£�		2021��03��29��
//��  �ȣ�		150��
/////////////////////////////////////////////////////////////////////////////////////////////
#include "stdafx.h"									//MFC��׼ͷ�ļ�
#include "CFactor.h"								//������ͷ�ļ�
#include "Helper.h"									//��������ͷ�ļ�


//��  �ƣ�		SumOutVariable()
//��  �ܣ�		���ݸ������������������
//��  ����		unsigned int
//����ֵ��		��
void CFactor::SumOutVariable(unsigned int nVariableID)
{
	///////////////////////////////////////////////
	//����2����͵���������Ҫͬѧ���

	//1.ɾ������ID�б�
	unsigned int nPos = 0;   //��Ҫ��ͱ�����λ��
	vector<unsigned int>::iterator it = m_VariableIDs.begin();
	while (it != m_VariableIDs.end()) {
		if ((*it) == nVariableID) {
			it = m_VariableIDs.erase(it);
			break;
		}
		else { 
			it++; 
			nPos++;
		}
	}

	//2.ɾ�������������ж�Ӧ��
	for (unsigned int i = 0; i < m_FactorRows.size(); i++) {
		unsigned int nCurrPos = 0;
		vector<unsigned int>::iterator it = m_FactorRows[i].ValueIDs.begin();
		while (it != m_FactorRows[i].ValueIDs.end()) {
			if (nCurrPos == nPos) {
				it = m_FactorRows[i].ValueIDs.erase(it);
				break;
			}
			else {
				it++;
				nCurrPos++;
			}
		}
	}

	//3.����ͬ�����
	vector<FACTOR_ROW> NewFactorRows;
	while (m_FactorRows.size()!=0) {
		FACTOR_ROW newrow = m_FactorRows[0];
		MergeIntoFirstRow(newrow);
		NewFactorRows.push_back(newrow);
	}
	m_FactorRows = NewFactorRows;
	///////////////////////////////////////////////
}

//��  �ƣ�		MergeIntoFirstRow()
//��  �ܣ�		�ۻ�����ֵ������
//��  ����		FACTOR_ROW&
//����ֵ��		��
void CFactor::MergeIntoFirstRow(FACTOR_ROW& first_row)
{
	//��������������
	vector<FACTOR_ROW>::iterator it = m_FactorRows.begin();

	//ɾ������
	it = m_FactorRows.erase(it);

	//����Ƿ����
	while (it != m_FactorRows.end())
	{
		//������ֵID���б��Ƿ����
		if (first_row.ValueIDs == it->ValueIDs)
		{
			//�ۼ�����ֵ
			first_row.fValue += it->fValue;

			//ɾ���������µ�����
			it = m_FactorRows.erase(it);
		}
		else
		{
			//���µ�����
			it++;
		}
	}
}