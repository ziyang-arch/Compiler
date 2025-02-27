
#ifndef TAC_H
#define TAC_H

#include<malloc.h>
#include<stdarg.h>
#include <iostream>
#include <vector>

#include "QuadrupleOperand.h"
#include "Quadruple.h"
#include "../GrammarTree/AST.h"
#include "../SymbolTable/ScopeStack_stl.h"

typedef unsigned int Label;

typedef struct TACCode
{
    int line; //在源代码中的行数
    Quadruple code;
    struct TACCode* prev;
    struct TACCode* next;
} TACCode;

typedef struct ARRAY_CODE            //四元式数组存储：四元式+数组空间
{
    TACCode* code;
    ScopeItem* size;
    ScopeItem* deviation;
} ARRAY_CODE;

//这个结构说明基本快通过首位节点的索引确定
/*
typedef struct basic_block {
    TACCode* begin;
    TACCode* end;
    vector <basic_block*> next;
} basic_block;
*/


    TACCode* BuildTAC(ASTTree* tree, ScopeItem &scopeItem, vector<ScopeItem> &stack, Label continuevalue, Label breakvalue, unsigned int &temp_num, unsigned int &label_num);
    TACCode* MergeTACItem(int num, ...);
    TACCode* TranslateExp(ASTTree* tree, ScopeItem &scopeItem, vector<ScopeItem> &stack, ScopeItem place, unsigned int &temp_num, unsigned int &label_num);
    TACCode* TranslateLvalAssign(ASTTree* tree, ScopeItem& scopeItem, vector<ScopeItem>& stack, ScopeItem place, unsigned int& temp_num, unsigned int& label_num);
    ARRAY_CODE TranslateArrayExps(ASTTree* tree, int leng, string arrayname, ScopeItem& scopeItem, vector<ScopeItem>& stack, unsigned int& temp_num, unsigned int& label_num);
    TACCode* TranslateCondition(ASTTree* tree, ScopeItem &scopeItem, vector<ScopeItem> &stack, unsigned int label_true, unsigned int label_false, unsigned int &temp_num, unsigned int &label_num);
    TACCode* TranslateFuncRParams(ASTTree* tree, ScopeItem &scopeItem, vector<ScopeItem> &stack, unsigned int &temp_num, unsigned int &label_num);
    TACCode* TranslateExps(ASTTree* tree, ScopeItem &scopeItem, vector<ScopeItem> &stack, unsigned int &temp_num, unsigned int &label_num);
    TACCode* TranslateStmt(ASTTree* tree, ScopeItem &scopeItem, vector<ScopeItem> &stack, Label continuevalue, Label breakvalue, unsigned int &temp_num, unsigned int &label_num);
    TACCode* TranslateInitVal(ASTTree* tree, ScopeItem& offset, int& layer, ScopeItem& scopeItem, vector<ScopeItem>& stack, ScopeItem place, unsigned int& temp_num, unsigned int& label_num);
    TACCode* TranslateInitValList(ASTTree* tree, ScopeItem& offset, int& layer, ScopeItem& scopeItem, vector<ScopeItem>& stack, ScopeItem place, unsigned int& temp_num, unsigned int& label_num);
    TACCode* TranslateRelExp(ASTTree* tree, ScopeItem& scopeItem, vector<ScopeItem>& stack, ScopeItem place, unsigned int label_true, unsigned int label_false, unsigned int& temp_num, unsigned int& label_num);
    TACCode* TranslateFuncRParams(ASTTree* tree, ScopeItem& scopeItem, vector<ScopeItem>& stack, unsigned int& temp_num, unsigned int& label_num);
    void DisplayTACCode(TACCode* entrance);
#endif
