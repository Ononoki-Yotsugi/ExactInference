/////////////////////////////////////////////////////////////////////////////////////////////
//�ļ�����		CFactor_ReduceGivenVariable.cpp
//��  �ܣ�		���ݸ����ı�����ֵ���������ӡ����ڼ����������ʷֲ�
//�����ߣ�		��־ǿ
//��  �ڣ�		2021��03��13��
//��  �£�		2021��03��14��
//��  �£�		2021��03��23��
//��  �£�		2021��03��29��
//��  �ȣ�		50��
/////////////////////////////////////////////////////////////////////////////////////////////
#include "stdafx.h"									//MFC��׼ͷ�ļ�
#include "CFactor.h"								//������ͷ�ļ�
#include "Helper.h"									//��������ͷ�ļ�


//��  �ƣ�		ReduceGivenVariable()
//��  �ܣ�		���ݸ����ı���ID��ֵID����������
//��  ����		unsigned int,unsigned int
//����ֵ��		��
void CFactor::ReduceGivenVariable(unsigned int nVariableID, unsigned int nValueID)
{
	//////////////////////////////////////////
	//����3�����ӻ�����Ҫͬѧ���
	//cout << nVariableID;
	//cout << nValueID;
	for (unsigned int i = 0; i < m_VariableIDs.size(); i++) {
		if (nVariableID == m_VariableIDs[i]) {
			//��ǰ���Ӿ�����Ҫ���������,��Ҫȥ�������ϵ�������
			for (vector<FACTOR_ROW>::iterator it = m_FactorRows.begin(); it != m_FactorRows.end();) {
				if ((*it).ValueIDs[i] != nValueID) {
					//��ǰ�����в�����������ȥ��
					it = m_FactorRows.erase(it);
					if (it == m_FactorRows.end()) {
						break;
					}
				}
				else { it++; }
			}
		}
	}
	//////////////////////////////////////////
}