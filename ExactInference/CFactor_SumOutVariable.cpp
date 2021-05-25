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