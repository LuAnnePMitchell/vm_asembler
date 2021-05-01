#include<algorithm>
#include<cassert>
#include<cstdio>
#include<cstdlib>
#include<fstream>
#include<iomanip>
#include<iostream>
#include<iterator>
#include<map>
#include<regex> 
#include<set>
#include<sstream>
#include<streambuf>
#include<stdio.h>
#include<string>
#include<vector>
using namespace std;
using std::sregex_token_iterator;

const int MEM_SIZE = 1000000;
const int TEMP_SIZE = 3;
const int C_SIZE = 7;
const int REG_SIZE = 14;

int getOpCode(string o) {
	if (o == "JMP")
		return 1;
	else if (o == "JMR")
		return 2;
	else if (o == "BNZ")
		return 3;
	else if (o == "BGT")
		return 4;
	else if (o == "BLT")
		return 5;
	else if (o == "BRZ")
		return 6;
	else if (o == "MOV")
		return 7;
	else if (o == "LDA")
		return 8;
	else if (o == "STR")
		return 9;
	else if (o == "LDR")
		return 10;
	else if (o == "STB")
		return 11;
	else if (o == "LDB")
		return 12;
	else if (o == "ADD")
		return 13;
	else if (o == "ADI")
		return 14;
	else if (o == "SUB")
		return 15;
	else if (o == "MUL")
		return 16;
	else if (o == "DIV")
		return 17;
	else if (o == "AND")
		return 18;
	else if (o == "OR")
		return 19;
	else if (o == "CMP")
		return 20;
	else if (o == "TRP")
		return 21;
	else
		return -1;
}

int getRegister(string r) {
	if (r == "R0")
		return 0;
	else if (r == "R1")
		return 1;
	else if (r == "R2")
		return 2;
	else if (r == "R3")
		return 3;
	else if (r == "R4")
		return 4;
	else if (r == "R5")
		return 5;
	else if (r == "R6")
		return 6;
	else if (r == "R7")
		return 7;
	else if (r == "R8")
		return 8;
	else if (r == "R9")
		return 9;
	else if (r == "R10")
		return 10;
	else if (r == "R11")
		return 11;
	else if (r == "R12")
		return 12;
	else
		return -1;
}

vector<string> labels = {};

int ifElseWhile(string l)
{
	int yesLabel = -1;
	for (int i = 0; i < labels.size(); i++) {
		if (l == labels[i]) {
			yesLabel = 1;
			return yesLabel;
		}
	}
	/*if (l == "ELSE1")
		return 1;
	else if (l == "ENDELSE1")
		return	1;
	else if (l == "WHILE1")
		return 1;
	else if (l == "ENDWHILE1")
		return 1;
	else if (l == "IF1")
		return 1;
	else if (l == "ENDIF1")
		return 1;
	else if (l == "END")
		return 1;
	else if (l == "WHILE2")
		return 1;
	else if (l == "ENDWHILE2")
		return 1;
	else if (l == "ELSE2")
		return 1;
	else if (l == "ENDELSE2")
		return 1;
	else if (l == "IF2")
		return 1;
	else if (l == "ENDIF2")
		return 1;
	else if (l == "TESTOvrFlw")
		return 1;
	else if (l == "OVERFLOW")
		return 1;
	else if (l == "TESTUndFlw")
		return 1;
	else if (l == "UNDERFLOW")
		return 1;
	else if (l == "Function1")
		return 1;
	else if (l == "PushAR")
		return 1;
	else if (l == "EndTESTOvrUndFlw")
		return 1;
	else if (l == "PopAR")
		return 1;
	else if (l == "ENDopdAR")
		return 1;
	else if (l == "ENDopd")
		return 1;
	else if (l == "IF_opd_0")
		return 1;
	else if (l == "ELSEIF_opd_1")
		return 1;
	else if (l == "ELSEIF_opd_2")
		return 1;
	else if (l == "ELSEIF_opd_3")
		return 1;
	else if (l == "ELSEIF_opd_4")
		return 1;
	else if (l == "ELSEIF_opd_5")
		return 1;
	else if (l == "ELSEIF_opd_6")
		return 1;
	else if (l == "ELSEIF_opd_7")
		return 1;
	else if (l == "ELSEIF_opd_8")
		return 1;
	else if (l == "ELSEIF_opd_9")
		return 1;
	else if (l == "ELSE_opd")
		return 1;
	else if (l == "IS_0")
		return 1;
	else if (l == "IS_1")
		return 1;
	else if (l == "IS_2")
		return 1;
	else if (l == "IS_3")
		return 1;
	else if (l == "IS_4")
		return 1;
	else if (l == "IS_5")
		return 1;
	else if (l == "IS_6")
		return 1;
	else if (l == "IS_7")
		return 1;
	else if (l == "IS_8")
		return 1;
	else if (l == "IS_9")
		return 1;
	else if (l == "Load_t_value")
		return 1;
	else if (l == "opd_AR")
		return 1;
	else if (l == "opd_AR_POP")
		return 1;
	else if (l == "END_opd_AR")
		return 1;
	else if (l == "ELSE_opd")
		return 1;
	else if (l == "opd_Function")
		return 1;
	else if (l == "Negative_k")
		return 1;
	else if (l == "POP_opdv_AR")
		return 1;
	else if (l == "flush_AR")
		return 1;
	else if (l == "END_flush_AR")
		return 1;
	else if (l == "flush_Function")
		return 1;
	else if (l == "flush_Overflow_Test")
		return 1;
	else if (l == "WHILE_flush")
		return 1;
	else if (l == "opd_Overflow_Test")
		return 1;
	else if (l == "opd_Underflow_Test")
		return 1;
	else if (l == "RETURN_opd")
		return 1;
	else if (l == "IF_opd_flag")
		return 1;
	else if (l == "POP_getData_AR")
		return 1;
	else if (l == "POP_AR")
		return 1;
	else if (l == "END_flush_Function")
		return 1;
	else if (l == "END_flush_AR")
		return 1;
	else if (l == "flush_AR")
		return 1;
	else if (l == "RETURN_flush_Function")
		return 1;
	else if (l == "flush_Function_AR_POP")
		return 1;
	else if (l == "flush_Function_Overflow_Test")
		return 1;
	else if (l == "flush_Function_Underflow_Test")
		return 1;
	else if (l == "getData")
		return 1;
	else if (l == "WHILE_getData")
		return 1;
	else if (l == "Num_Too_Big")
		return 1;
	else if (l == "getData_Overflow_Test")
		return 1;
	else if (l == "getData_Underflow_Test")
		return 1;
	else if (l == "getData_Overflow_Test_2")
		return 1;
	else if (l == "getData_AR_1")
		return 1;
	else if (l == "getData_AR_2")
		return 1;
	else if (l == "getData_AR_3")
		return 1;
	else if (l == "getData_AR_4")
		return 1;
	else if (l == "getData_AR_POP")
		return 1;
	else if (l == "getData_Function")
		return 1;
	else if (l == "END_getData_AR_1")
		return 1;
	else if (l == "reset_Overflow_Test_1")
		return 1;
	else if (l == "reset_Overflow_Test_2")
		return 1;
	else if (l == "reset_AR_1")
		return 1;
	else if (l == "END_reset_AR")
		return 1;
	else if (l == "reset_Function")
		return 1;
	else if (l == "WHILE_reset")
		return 1;
	else if (l == "reset_Values")
		return 1;
	else if (l == "RETURN_reset_Function")
		return 1;
	else if (l == "reset_Function_Underflow_Test")
		return 1;
	else if (l == "reset_Function_AR_POP")
		return 1;
	else if (l == "main")
		return 1;
	else if (l == "MAIN") {
		return 1;
	}
	else if (l == "flush_AR_Overflow_Test")
		return 1;
	else if (l == "RETURN_getData")
		return 1;
	else if (l == "WHILE_1_main")
		return 1;
	else if (l == "IF_1_main")
		return 1;
	else if (l == "ELSE_1_main")
		return 1;
	else if (l == "END_ELSE_1_main")
		return 1;
	else if (l == "IS_IT_MINUS")
		return 1;
	else if (l == "WHILE_2_main")
		return 1;
	else if (l == "getData_Overflow_Test_1")
		return 1;
	else if (l == "getData_Overflow_Test_2")
		return 1;
	else if (l == "getData_Overflow_Test_3")
		return 1;
	else if (l == "getData_Overflow_Test_4")
		return 1;
	else if (l == "WHILE_getData")
		return 1;
	else if (l == "END_WHILE_getData")
		return 1;
	else if (l == "WHILE_getData_Function")
		return 1;
	else if (l == "IF_getData_Function")
		return 1;
	else if (l == "IF_2_main")
		return 1;
	else if (l == "ELSE_2_main")
		return 1;
	else if (l == "WHILE_3_main")
		return 1;
	else if (l == "IF_3_main")
		return 1;
	else if (l == "reset_cnt")
		return 1;*/
	return yesLabel;
}

void addIntToMemArray(string tempInt, int address, char mem[])
{
	int intTemp = stoi(tempInt);
	int* intLabelAddress = (int*)(mem + address);
	*intLabelAddress = intTemp;
}

void addCharToMemArray(string charTemp, int address, char mem[])
{
	char* c = const_cast<char*>(charTemp.c_str());
	mem[address] = c[1];
}

void addLabelAddressToMemArray(int labelAddr, int address, char mem[])
{
	int* ii = (int*)(mem + address);
	*ii = labelAddr;
}

void addRegisterToMemArray(int regist, int PC, char mem[])
{
	int* ii = (int*)(mem + PC);
	*ii = regist;
}

void addOpCodeToMemArray(int opCode, int PC, char mem[])
{
	int* ii = (int*)(mem + PC);
	*ii = opCode;
}

int intToAscii(int number) {
	return '0' + number;
}
int main(int argc, char* argv[])
{
	int *ii, *intLabelAddress, labelAddr;
	char *cc, *charLabelAddress;
	char mem[MEM_SIZE] = { "" };
	char c[C_SIZE] = { "" };
	char tempArr[100] = { "" };
	int registers[REG_SIZE] = { 0 };
	int PC = 0;
	int PFP = 0;
	int SL = 0;
	int SB = (MEM_SIZE - 5);
	int FP = (MEM_SIZE - 5);
	int SP = (MEM_SIZE - 5);
	registers[8] = PC;
	registers[9] = SB;
	registers[10] = FP;
	registers[11] = SP;
	registers[12] = SL;
	registers[13] = 0;
	int start = 0;
	labelAddr = 0;
	intLabelAddress = (int*)(mem[labelAddr]);
	cc = mem + PC;
	map<string, int> symbolTable;
	string fileName;

	enum instructions {
		JMP = 1, JMR = 2, BNZ = 3, BGT = 4, BLT = 5, BRZ = 6, MOV = 7, LDA = 8, STR = 9, LDR = 10, STB = 11, LDB = 12, ADD = 13,
		ADI = 14, SUB = 15, MUL = 16, DIV = 17, AND = 18, OR = 19, CMP = 20, TRP = 21, STR2 = 22, LDR2 = 23, STB2 = 24, LDB2 = 25
	};
	ifstream in;
	if (argc != 2)
	{

		// there was no file, so ask the user to enter the file name
		std::cout << "No file Found. Please enter file name: ";
		// save the name of the file into fileName
		cin >> fileName;
		in.open(fileName); // check to see if the filename entered opens
		while (in.fail()) {
			in.clear();
			cout << "\n" << "Incorrect filename, please enter it again:   ";
			cin >> fileName;
			in.open(fileName);

			//in.open(fileName);
		}
		in.close();
	}
	// save argv[1] in variable fileName
	else
	{
		fileName = argv[1];
	}
	int passCount = 1;
	// Assembler starts

	while (passCount <= 2)
	{

		PC = 0;
		SL = 0;
		int opCode = 0;
		int sourceReg = 0;
		int destReg = 0;

		// open assembly file

		in.open(fileName);

		// begin while loop that reads in the assembly file
		while (!(in.eof()))
		{
			string temp; // temp holds the current line read in from assembly file

			getline(in, temp); // get a line from assembly file, save in temp

			temp = temp.substr(0, temp.find(';'));
			regex r("[\\s\\n]"); // regex pattern that breaks on space and newline

			vector<string> tempVector; // temporary vector I store the assembly file, that iterates below to find each token

			copy(sregex_token_iterator(temp.begin(), temp.end(), r, -1), 			// copy each token into the tempVector
				sregex_token_iterator(), back_insert_iterator<vector<string>>(tempVector));

			// iterate through the tempVector and populate the Symbol Table on first pass, populate memory on second pass
			for (vector<string>::const_iterator it = tempVector.begin(); it < tempVector.end(); it++)
			{

				string label = *it;
				string code = *it;
				opCode = getOpCode(code);
				string ifStatementLabel = *it;
				int condState = ifElseWhile(ifStatementLabel);

				//if (opCode == -1) {	// it means it has a label, might be a directive or code

				//if (opCode == -1 && condState == -1)
				//{
				//	if (*it == ".INT")
				//	{
				//		*it++;
				//		// first pass do this:
				//		if (passCount == 1)
				//		{
				//			//symbolTable.insert(pair<string, int>(label, PC));
				//			start += 4;
				//			//std::cout << "it: " << *it << endl;
				//		}
				//		// second pass save the value of *it into mem array:
				//		else
				//		{
				//			string intTemp = *it;
				//			addIntToMemArray(intTemp, PC, mem);
				//		}
				//		PC += 4;
				//		SL += 4;
				//	}
				//	else if (*it == ".BYT")
				//	{
				//		*it++;
				//		if (passCount == 1)
				//		{
				//			//symbolTable.insert(pair<string, int>(label, PC));
				//			start += 1;
				//			//std::cout << "it: " << *it << endl;
				//		}
				//		else
				//		{
				//			string charTemp = *it;
				//			addCharToMemArray(charTemp, PC, mem);
				//		}
				//		PC += 1;
				//		SL += 1;
				//	}
					//else
					//{
				*it++;
				if (*it == ".INT")
				{
					*it++;
					// first pass do this:
					if (passCount == 1)
					{
						symbolTable.insert(pair<string, int>(label, PC));
						start += 4;
						//std::cout << "it: " << *it << endl;
					}
					// second pass save the value of *it into mem array:
					else
					{
						string intTemp = *it;
						labelAddr = symbolTable.find(label)->second;
						addIntToMemArray(intTemp, labelAddr, mem);
					}
					PC += 4;
					SL += 4;
				}
				else if (*it == ".BYT")
				{
					*it++;
					if (passCount == 1)
					{
						if (*it == "'\\n'") {
							symbolTable.insert(pair<string, int>(label, PC));
							start += 4;
							PC += 4;
							SL += 4;
						}
						else if (*it == "'\\s'") {
							symbolTable.insert(pair<string, int>(label, PC));
							start += 4;
							PC += 4;
							SL += 4;
						}
						else {
							symbolTable.insert(pair<string, int>(label, PC));
							start += 1;
							//std::cout << "it: " << *it << endl;
							PC += 1;
							SL += 1;
						}
					}
					else
					{
						if (*it == "'\\n'" || *it == "'\\s'") {
							string intTemp = *it;
							labelAddr = symbolTable.find(label)->second;
							if (*it == "'\\s'") {
								addIntToMemArray("32", labelAddr, mem);
							}
							else {
								addIntToMemArray("10", labelAddr, mem);
							}
							PC += 4;
							SL += 4;
						}
						else {
							string charTemp = *it;
							labelAddr = symbolTable.find(label)->second;
							addCharToMemArray(charTemp, labelAddr, mem);
							PC += 1;
							SL += 1;
						}
					}


				}
				//}

				else
				{
					if (condState == -1) {
						if (passCount == 1) {
							if (label != "") {
								int tempOpCode = getOpCode(label);
								if (tempOpCode == -1) {
									labels.push_back(label);
								}
							}
						}
					}
					//*it++;
					if (opCode == -1)
					{
						opCode = getOpCode(*it);
						if (passCount == 1)
						{
							symbolTable.insert(pair<string, int>(label, PC));
							//cout << "label: " << label << endl;
						}
						*it++;
					}
					if (passCount == 1)
					{
						if (opCode == 1) // it's a JMP, only has one operand
						{
							PC += 12;
						}
						else if (opCode == 2) // it's a JMR, only has one operand
						{
							PC += 12;
						}
						else if (opCode == 21) // it's TRP, only has one operand
						{
							PC += 12;
						}
						else
						{
							*it++;
							PC += 12;
						}
						SL += 4;
					}
					else
					{
						if (opCode == JMP)	// JMP to specified address in register 1
						{
							addOpCodeToMemArray(opCode, PC, mem);
							PC += 4;
							labelAddr = symbolTable.find(*it)->second;
							addLabelAddressToMemArray(labelAddr, PC, mem);
							PC += 8;
						}
						else if (opCode == JMR)
						{
							//cout << "opCode: " << opCode << endl;
							addOpCodeToMemArray(opCode, PC, mem);
							PC += 4;
							sourceReg = getRegister(*it);
							addRegisterToMemArray(sourceReg, PC, mem);
							PC += 8;
						}
						else if (opCode == BNZ)
						{
							//cout << "opCode: " << opCode << endl;
							addOpCodeToMemArray(opCode, PC, mem);
							PC += 4;
							sourceReg = getRegister(*it);
							addRegisterToMemArray(sourceReg, PC, mem);
							*it++;
							PC += 4;
							labelAddr = symbolTable.find(*it)->second;
							addLabelAddressToMemArray(labelAddr, PC, mem);
							PC += 4;
						}
						// not sure if BGT is functional
						else if (opCode == BGT)
						{
							addOpCodeToMemArray(opCode, PC, mem);
							PC += 4;
							sourceReg = getRegister(*it);
							addRegisterToMemArray(sourceReg, PC, mem);
							*it++;
							PC += 4;
							labelAddr = symbolTable.find(*it)->second;
							addLabelAddressToMemArray(labelAddr, PC, mem);
							PC += 4;
						}
						// not sure if BLT is functional
						else if (opCode == BLT)
						{
							addOpCodeToMemArray(opCode, PC, mem);
							PC += 4;
							sourceReg = getRegister(*it);
							addRegisterToMemArray(sourceReg, PC, mem);
							*it++;
							PC += 4;
							labelAddr = symbolTable.find(*it)->second;
							addLabelAddressToMemArray(labelAddr, PC, mem);
							PC += 4;
						}
						// not sure if BRZ is functional
						else if (opCode == BRZ)
						{
							addOpCodeToMemArray(opCode, PC, mem);
							PC += 4;
							sourceReg = getRegister(*it);
							addRegisterToMemArray(sourceReg, PC, mem);
							*it++;
							PC += 4;
							labelAddr = symbolTable.find(*it)->second;
							addLabelAddressToMemArray(labelAddr, PC, mem);
							PC += 4;
						}
						else if (opCode == MOV)
						{
							addOpCodeToMemArray(opCode, PC, mem);
							PC += 4;
							destReg = getRegister(*it);
							addRegisterToMemArray(destReg, PC, mem);
							*it++;
							PC += 4;
							sourceReg = getRegister(*it);
							addRegisterToMemArray(sourceReg, PC, mem);
							PC += 4;
						}
						else if (opCode == LDA)
						{
							addOpCodeToMemArray(opCode, PC, mem);
							PC += 4;
							destReg = getRegister(*it);
							addRegisterToMemArray(destReg, PC, mem);
							*it++;
							PC += 4;
							labelAddr = symbolTable.find(*it)->second;
							addLabelAddressToMemArray(labelAddr, PC, mem);
							PC += 4;
						}
						else if (opCode == STR)
						{
							addOpCodeToMemArray(opCode, PC, mem);
							int *tempSTR;
							tempSTR = (int*)(mem + PC);
							PC += 4;
							sourceReg = getRegister(*it);
							addRegisterToMemArray(sourceReg, PC, mem);
							*it++;
							PC += 4;
							destReg = getRegister(*it);
							if (destReg == -1) // it's label
							{
								labelAddr = symbolTable.find(*it)->second;
								addLabelAddressToMemArray(labelAddr, PC, mem);
							}
							else
							{
								opCode = STR2;
								*tempSTR = opCode;
								addRegisterToMemArray(destReg, PC, mem);
							}
							PC += 4;
						}
						else if (opCode == LDR)
						{
							addOpCodeToMemArray(opCode, PC, mem);
							int *tempLDR;
							// save this PC location incase 2nd operand is a register, not a label
							tempLDR = (int*)(mem + PC);
							PC += 4;
							destReg = getRegister(*it);
							addRegisterToMemArray(destReg, PC, mem);
							*it++;
							PC += 4;
							sourceReg = getRegister(*it);
							// if *it is not a register do this:
							if (sourceReg == -1)
							{
								labelAddr = symbolTable.find(*it)->second;
								addLabelAddressToMemArray(labelAddr, PC, mem);
							}
							else  //*it is a register do this:
							{	// change value in mem location where opCode is stored to 23, which is LDR2 in enum above
								opCode = LDR2;
								*tempLDR = opCode;
								addRegisterToMemArray(sourceReg, PC, mem);
							}
							PC += 4;
						}
						else if (opCode == STB)
						{
							int *tempSTB;
							tempSTB = (int*)(mem + PC);
							addOpCodeToMemArray(opCode, PC, mem);
							//cout << "opCode ii: " << *ii << endl;
							PC += 4;
							sourceReg = getRegister(*it);
							addRegisterToMemArray(sourceReg, PC, mem);
							*it++;
							PC += 4;
							destReg = getRegister(*it);
							if (destReg == -1)
							{
								labelAddr = symbolTable.find(*it)->second;
								addLabelAddressToMemArray(labelAddr, PC, mem);
							}
							else
							{
								opCode = STB2;
								*tempSTB = opCode;
								addRegisterToMemArray(destReg, PC, mem);
							}
							PC += 4;
						}
						else if (opCode == LDB)
						{
							int *tempLDB;
							tempLDB = (int*)(mem + PC);
							addOpCodeToMemArray(opCode, PC, mem);
							PC += 4;
							destReg = getRegister(*it);
							addRegisterToMemArray(destReg, PC, mem);
							*it++;
							PC += 4;

							sourceReg = getRegister(*it);
							// if *it is not a register do this:
							if (sourceReg == -1)
							{
								labelAddr = symbolTable.find(*it)->second;
								addLabelAddressToMemArray(labelAddr, PC, mem);
							}
							else  //*it is a register do this:
							{	// change value in mem location where opCode is stored to 23, which is LDR2 in enum above
								opCode = LDB2;
								*tempLDB = opCode;
								addRegisterToMemArray(sourceReg, PC, mem);
							}
							PC += 4;
						}
						else if (opCode == ADD)
						{
							addOpCodeToMemArray(opCode, PC, mem);
							//cout << "opCode: " << opCode << endl;
							PC += 4;
							destReg = getRegister(*it);
							addRegisterToMemArray(destReg, PC, mem);
							*it++;
							PC += 4;
							//cout << "*it: " << *it << endl;
							sourceReg = getRegister(*it);
							addRegisterToMemArray(sourceReg, PC, mem);
							PC += 4;
						}
						else if (opCode == ADI)
						{
							addOpCodeToMemArray(opCode, PC, mem);
							//cout << "opCode: " << opCode << endl;
							PC += 4;
							destReg = getRegister(*it);
							addRegisterToMemArray(destReg, PC, mem);
							*it++;
							PC += 4;
							//cout << "*it: " << *it << endl;
							string immedValue = *it;
							ii = (int*)(mem + PC);
							*ii = stoi(immedValue);
							PC += 4;
						}
						else if (opCode == SUB)
						{
							addOpCodeToMemArray(opCode, PC, mem);
							PC += 4;
							destReg = getRegister(*it);
							addRegisterToMemArray(destReg, PC, mem);
							*it++;
							PC += 4;
							sourceReg = getRegister(*it);
							addRegisterToMemArray(sourceReg, PC, mem);
							PC += 4;
						}
						else if (opCode == MUL)
						{
							addOpCodeToMemArray(opCode, PC, mem);
							PC += 4;
							destReg = getRegister(*it);
							addRegisterToMemArray(destReg, PC, mem);
							*it++;
							PC += 4;
							sourceReg = getRegister(*it);
							addRegisterToMemArray(sourceReg, PC, mem);
							PC += 4;
						}
						else if (opCode == DIV)
						{
							addOpCodeToMemArray(opCode, PC, mem);
							PC += 4;
							destReg = getRegister(*it);
							addRegisterToMemArray(destReg, PC, mem);
							*it++;
							PC += 4;
							sourceReg = getRegister(*it);
							addRegisterToMemArray(sourceReg, PC, mem);
							PC += 4;
						}
						else if (opCode == AND)
						{
							addOpCodeToMemArray(opCode, PC, mem);
							PC += 4;
							destReg = getRegister(*it);
							addRegisterToMemArray(destReg, PC, mem);
							*it++;
							PC += 4;
							sourceReg = getRegister(*it);
							addRegisterToMemArray(sourceReg, PC, mem);
							PC += 4;
						}
						else if (opCode == OR)
						{
							addOpCodeToMemArray(opCode, PC, mem);
							PC += 4;
							destReg = getRegister(*it);
							addRegisterToMemArray(destReg, PC, mem);
							*it++;
							PC += 4;
							sourceReg = getRegister(*it);
							addRegisterToMemArray(sourceReg, PC, mem);
							PC += 4;
						}
						else if (opCode == CMP)
						{
							addOpCodeToMemArray(opCode, PC, mem);
							PC += 4;
							destReg = getRegister(*it);
							addRegisterToMemArray(destReg, PC, mem);
							*it++;
							PC += 4;
							sourceReg = getRegister(*it);
							addRegisterToMemArray(sourceReg, PC, mem);
							PC += 4;
						}
						else if (opCode == TRP)
						{
							addOpCodeToMemArray(opCode, PC, mem);
							PC += 4;
							string immVal = *it;
							ii = (int*)(mem + PC);
							*ii = stoi(immVal);
							PC += 8;
						}
						else
						{
							//*it++;
							//PC += 12;
						}
						SL += 12;
					}

				}
			}
		}
		passCount++;

		in.close();
	}// ***END Assembler***

	//  ***BEGIN VM***

	//struct that serves as Instruction Register
	struct myInstruction
	{
		int instructionReg[3] = { 0 };
		int opCde;
		int opd1;
		int opd2;
	}IR, IR_copy;

	PC = start;	// location where instructions begin

	registers[8] = PC;
	registers[12] = SL;
	//std::cout << "PC: " << PC << endl;
	//std::cout << "Register 12: " << registers[12] << endl;

	char *vmChar, letter;
	int vmInt = 0;

	while (!(&PC == nullptr))
	{
		//fetch the first instructions and put them into the struct myInstruction via IR.opCde, IR.opd1, IR.opd2
		ii = (int*)(mem + PC);
		IR.opCde = *ii;
		PC += 4;
		ii = (int*)(mem + PC);
		IR.opd1 = *ii;
		PC += 4;
		ii = (int*)(mem + PC);
		IR.opd2 = *ii;
		PC += 4;
		registers[8] = PC;

		//memcpy(&IR_copy, &IR, sizeof(IR));

		switch (IR.opCde)  								 	// use switch to parse out the opcodes
		{
		case JMP:

			PC = IR.opd1;
			//registers[8] = PC;
			break;

		case JMR:
			PC = registers[IR.opd1];
			//registers[8] = PC;
			break;

		case BRZ:
			if (registers[IR.opd1] == 0)
			{
				PC = IR.opd2;
				//registers[8] = PC;
			}
			break;

		case BGT:
			labelAddr = IR.opd2;						// get the address in memory where value is stored
			if (registers[IR.opd1] > 0)
			{
				PC = IR.opd2;
				//registers[8] = PC;
			}
			break;

		case BNZ:
			labelAddr = IR.opd2;						// get the address in memory where value is stored
			if (registers[IR.opd1] != 0)
			{
				PC = IR.opd2;
				//registers[8] = PC;
			}
			break;

		case BLT:
			labelAddr = IR.opd2;
			if (registers[IR.opd1] < 0)
			{
				int vmTemp = registers[IR.opd1];
				while (vmTemp < 0)
				{
					vmTemp = vmTemp + 2;
				}
				if (vmTemp == 0)
				{
					break;
				}
				else
				{
					PC = labelAddr;
					//registers[8] = PC;
				}
			}
			break;

		case MOV:										// move value from source register into destination register
			registers[IR.opd1] = registers[IR.opd2];
			break;

		case LDA:
			registers[IR.opd1] = IR.opd2;
			break;

		case STR:
			labelAddr = IR.opd2;						// get the address in memory where value is stored
			intLabelAddress = (int*)(mem + labelAddr);	// an integer size chunk of memory is what we want
			*intLabelAddress = registers[IR.opd1];
			break;

		case LDR:										// load an integer into destination register from memory
			labelAddr = IR.opd2;						// get the address in memory where value is stored
			intLabelAddress = (int*)(mem + labelAddr);	// an integer size chunk of memory is what we want
			vmInt = *intLabelAddress;					// get the value from that chunk of memory and save it in vmInt
			//if (vmInt > 500 && vmInt < 600)							// check to see if the value is newline, comma or space because added 500 to each value 
			//{
			//	vmInt = *intLabelAddress - 500;			// to get their Ascii values, need to subtract 500 now
			//	registers[IR.opd1] = vmInt;				// save the Ascii value into destination register
			//}
			//else
			//{
			registers[IR.opd1] = vmInt;	// save the integer value into the destination register
		//}
			break;

		case STB:
			labelAddr = IR.opd2;
			vmChar = (char*)mem + labelAddr;
			//letter = IR.opd1;
			letter = registers[IR.opd1];
			*vmChar = letter;
			break;

		case LDB:										// load an integer into destination register from memory
			labelAddr = IR.opd2;						// get the address in memory where value is stored
			vmChar = (char*)mem + labelAddr;			// a character size chunk of memory is what we want
			letter = *vmChar;
			registers[IR.opd1] = 0;
			registers[IR.opd1] = letter;
			break;

		case ADD:
			registers[IR.opd1] = registers[IR.opd1] + registers[IR.opd2];
			//cout << " Added opd1 + opd2:  " << registers[IR.opd1] << endl;
			break;

		case ADI:
			registers[IR.opd1] = registers[IR.opd1] + IR.opd2;
			break;

		case SUB:
			registers[IR.opd1] = registers[IR.opd1] - registers[IR.opd2];
			break;

		case MUL:
			registers[IR.opd1] = registers[IR.opd1] * registers[IR.opd2];
			break;

		case DIV:
			registers[IR.opd1] = registers[IR.opd1] / registers[IR.opd2];
			break;

		case AND:
			if (registers[IR.opd1] == 1 && registers[IR.opd2] == 1) {
				registers[IR.opd1] = 1;
			}
			else {
				registers[IR.opd1] = 0;
			}
			break;

		case OR:
			if (registers[IR.opd1] == 1 || registers[IR.opd2] == 1) {
				registers[IR.opd1] = 1;
			}
			else {
				registers[IR.opd1] = 0;
			}
			break;

		case CMP:
			if (registers[IR.opd1] == registers[IR.opd2])
			{
				registers[IR.opd1] = 0;
			}
			else if (registers[IR.opd1] > registers[IR.opd2])
			{
				registers[IR.opd1] = 1;
			}
			else
			{
				registers[IR.opd1] = -1;
			}
			break;

		case TRP:
			char myChar;
			int asciiValue;

			switch (IR.opd1)
			{
			case 0:
				exit(1);

			case 1:
				//if (registers[3] == 13)
				//{
					//std::cout << "\n";
				//}
				//else if (registers[3] == 32)
				//{
				//	std::cout << char(registers[3]);
				//}
				//else if (registers[3] == 44)
				//{
				//	std::cout << char(registers[3]);
				//}
				//else if (registers[3] == 45)
				//{
				//	std::cout << char(registers[3]);
				//}
				//else if (registers[3] == 61)
				//{
				//	std::cout << char(registers[3]);
				//}
				//else
				//{
				std::cout << int(registers[3]);
				//}
				break;

			case 2:
				//std::cout << "Please enter a number:  ";
				//int myInt;
				std::cin >> vmInt;
				registers[3] = vmInt;
				//std::cout << "number is: " << int(registers[3]) << endl;
				break;

			case 3:

				//myChar = char(registers[3]);
				//cout << char(myChar);
				if (registers[3] == 62) {
					cout << '\n';
					std::cout << char(registers[3]);
				}
				//cout << intToAscii(registers[3]);
				else if (registers[3] == 32) {
					cout << " ";
				}
				else if (registers[3] == 10) {
					cout << '\n';
					//cout << " ";
				}
				else if (registers[3] == 92) {
					cout << '\n';
					//cout << " ";
				}

				else {
					//cout << myChar;
					//cout << '\n';
					std::cout << char(registers[3]);
					//cout << " ";
				}
				break;

			case 4:
				myChar = 0;
				registers[3] = 0;
				//int tempCnt = registers[0];
				//int i = 0;
				std::cout << "Please enter a character ";
				cin >> myChar;
				//myChar = getchar();
				registers[3] = myChar;
				//std::cout << "character is: " << char(registers[3]) << endl;
				break;
				//if (registers[0] == 0)
				//{
				//	for (int j = 0; j < sizeof(tempArr); j++)
				//	{
				//		tempArr[j] = 0;
				//		j++;
				//	}
				//	myChar = getchar();
				//	std::cout << "Please enter a character ";
				//	do
				//	{
				//		myChar = getchar();
				//		if (myChar == '\n')
				//		{
				//			tempArr[i] = 13;
				//			i++;
				//		}
				//		else
				//		{
				//			tempArr[i] = myChar;
				//			i++;
				//		}
				//		//tempArr.push_back(13);
				//	//tempArr.push_back(myChar);
				//		tempCnt++;
				//		registers[5] = tempCnt;

				//	} while (myChar != '\n');
				//	registers[3] = tempArr[0];
				//}
				//else if (registers[0] == 1)
				//{
				//	if (tempArr[0] == '+' || '-')
				//	{
				//		if (tempArr[tempCnt] == '\n')
				//		{
				//			registers[3] = 13;
				//		}
				//		else
				//		{
				//			registers[3] = tempArr[1];
				//		}
				//	}
				//	else
				//	{
				//		if (tempArr[tempCnt] == '\n')
				//		{
				//			registers[3] = 13;
				//		}
				//		else
				//		{
				//			registers[3] = tempArr[0];
				//		}
				//	}
				//	registers[5] = tempCnt;
				//}
				//else
				//{
				//	if (tempArr[0] == '+')
				//	{
				//		if (tempArr[tempCnt] == '\n')
				//		{
				//			registers[3] = 13;
				//		}
				//		else
				//		{
				//			registers[3] = tempArr[tempCnt];
				//		}
				//	}
				//	else if (tempArr[0] == '-')
				//	{
				//		if (tempArr[tempCnt] == '\n')
				//		{
				//			registers[3] = 13;
				//		}
				//		else
				//		{
				//			registers[3] = tempArr[tempCnt];
				//		}
				//	}
				//	else
				//	{
				//		if (tempArr[tempCnt] == '\n')
				//		{
				//			registers[3] = 13;
				//		}
				//		else
				//		{
				//			registers[3] = tempArr[tempCnt - 1];
				//		}
				//	}
				//	registers[5] = tempCnt;
				//}
				////std::cout << "character is: " << char(registers[3]) << endl;
				//break;

			}
			break;

		case STR2:
			labelAddr = registers[IR.opd2];
			//labelAddr = IR.opd2;
			intLabelAddress = (int*)(mem + labelAddr);
			*intLabelAddress = registers[IR.opd1];
			//cout << "Value Stored: " << *intLabelAddress << endl;
			//cout << "Address stored at: " << labelAddr << endl;
			break;

		case LDR2:
			labelAddr = registers[IR.opd2];
			intLabelAddress = (int*)(mem + labelAddr);	// an integer size chunk of memory is what we want
			vmInt = *intLabelAddress;
			registers[IR.opd1] = vmInt;
			//cout << "Value loaded in: " << IR.opd1 << " is: " << vmInt << endl;
			//cout << "Address loaded from: " << labelAddr << endl;
			break;

		case STB2:
			labelAddr = registers[IR.opd2];
			vmChar = (char*)(mem + labelAddr);
			*vmChar = registers[IR.opd1];
			//cout << "Value Stored: " << *vmChar << endl;
			//cout << "Address stored at: " << labelAddr << endl;

			break;

		case LDB2:
			labelAddr = registers[IR.opd2];
			vmChar = (char*)(mem + labelAddr);			// a character size chunk of memory is what we want
			letter = *vmChar;
			registers[IR.opd1] = letter;
			//cout << "Value loaded in: " << IR.opd1 << " is: " << *vmChar << endl;
			//cout << "Address stored at: " << labelAddr << endl;
			break;
		}
	}
	return 0;
}
