//
//  main.cpp
//  GRN
//
//  Created by jinyang on 13-7-26.
//  Copyright (c) 2013年 Li Jinyang. All rights reserved.
//

#include <iostream>
#include "Sequence.h"
#include "GRN.h"

using namespace std;

int main(){
    //the index is gengeNumber;
    string dna[3];
    dna[0] = "ATGAAACGCCCGGACTACAGAACATTACAGGCACTGGATGCGGTGATACGTGAACGAGGATTTGAGCGCGCGGCACAAAAGCTGTGCATTACACAATCAGCCGTCTCACAGCGCATTAAGCAACTGGAAAATATGTTCGGGCAGCCGCTGTTGGTGCGTACCGTACCGCCGCGCCCGACGGAACAAGGGCAAAAACTGCTGGCACTGCTGCGCCAGGTGGAGTTGCTGGAAGAAGAGTGGCTGGGCGATGAACAAACCGGTTCGACTCCGCTGCTGCTTTCACTGGCGGTCAACGCCGACAGTCTGGCGACGTGGTTGCTTCCTGCACTGGCTCCTGTGTTGGCTGATTCGCCTATCCGCCTCAACTTGCAGGTAGAAGATGAAACCCGCACTCAGGAACGTCTGCGCCGCGGCGAAGTGGTCGGCGCGGTGAGTATTCAACATCAGGCGCTGCCGAGTTGTCTTGTCGATAAACTTGGTGCGCTCGACTATCTGTTCGTCAGCTCAAAACCCTTTGCCGAAAAATATTTCCCTAACGGCGTAACGCGTTCGGCATTACTGAAAGCGCCAGTGGTCGCGTTTGACCATCTTGACGATATGCACCAGGCCTTTTTGCAGCAAAACTTCGATCTGCCTCCAGGCAGCGTGCCCTGCCATATCGTTAATTCTTCAGAAGCGTTCGTACAACTTGCTCGCCAGGGCACCACCTGCTGTATGATCCCGCACCTGCAAATCGAGAAAGAGCTGGCCAGCGGTGAACTGATTGACTTAACGCCTGGGCTATTTCAACGACGGATGCTCTACTGGCACCGCTTTGCTCCTGAAAGCCGCATGATGCGTAAAGTCACTGATGCGTTACTCGATTATGGTCACAAAGTCCTTCGTCAGGATTAA";
    dna[1] = "ATGACGCAGGATGAATTGAAAAAAGCAGTAGGATGGGCGGCACTTCAGTATGTTCAGCCCGGCACCATTGTTGGTGTAGGTACAGGTTCCACCGCCGCACACTTTATTGACGCGCTCGGTACAATGAAAGGCCAGATTGAAGGGGCCGTTTCCAGTTCAGATGCTTCCACTGAAAAACTGAAAAGCCTCGGCATTCACGTTTTTGATCTCAACGAAGTCGACAGCCTTGGCATCTACGTTGATGGCGCAGATGAAATCAACGGCCACATGCAAATGATCAAAGGCGGCGGCGCGGCGCTGACCCGTGAAAAAATCATTGCTTCGGTTGCAGAAAAATTTATCTGTATTGCAGACGCTTCCAAGCAGGTTGATATTCTGGGTAAATTCCCGCTGCCAGTAGAAGTTATCCCGATGGCACGTAGTGCAGTGGCGCGTCAGCTGGTGAAACTGGGCGGTCGTCCGGAATACCGTCAGGGCGTGGTGACCGATAATGGCAACGTGATCCTCGACGTCCACGGCATGGAAATCCTTGACCCGATAGCGATGGAAAACGCCATAAATGCGATTCCTGGCGTGGTGACTGTTGGCTTGTTTGCTAACCGTGGCGCGGACGTTGCGCTGATTGGCACACCTGACGGTGTCAAAACCATTGTGAAATGA";
    dna[2] = "ATGTCTTATCAGTATGTTAACGTTGTCACTATCAACAAAGTGGCGGTCATTGAGTTTAACTATGGCCGAAAACTTAATGCCTTAAGTAAAGTCTTTATTGATGATCTTATGCAGGCGTTAAGCGATCTCAACCGGCCGGAAATTCGCTGTATCATTTTGCGCGCACCGAGTGGATCCAAAGTCTTCTCCGCAGGTCACGATATTCACGAACTGCCGTCTGGCGGTCGCGATCCGCTCTCCTATGATGATCCATTGCGTCAAATCACCCGCATGATCCAAAAATTCCCGAAACCGATCATTTCGATGGTGGAAGGTAGTGTTTGGGGTGGCGCATTTGAAATGATCATGAGTTCCGATCTGATCATCGCCGCCAGTACCTCAACCTTCTCAATGACGCCTGTAAACCTCGGCGTCCCGTATAACCTGGTCGGCATTCACAACCTGACCCGCGACGCGGGCTTCCACATTGTCAAAGAGCTGATTTTTACCGCTTCGCCAATCACCGCCCAGCGCGCGCTGGCTGTCGGCATCCTCAACCATGTTGTGGAAGTGGAAGAACTGGAAGATTTCACCTTACAAATGGCGCACCACATCTCTGAGAAAGCGCCGTTAGCCATTGCCGTTATCAAAGAAGAGCTGCGTGTACTGGGCGAAGCACACACCATGAACTCCGATGAATTTGAACGTATTCAGGGGATGCGCCGCGCGGTGTATGACAGCGAAGATTACCAGGAAGGGATGAACGCTTTCCTCGAAAAACGTAAACCTAATTTCGTTGGTCATTAA";
    int dna_size[3];
    dna_size[0] = 894;
    dna_size[1] = 660;
    dna_size[2] = 786;
    
    //cout << dna[0].size() << endl;
    //cout << dna[1].size() << endl;
    //cout << dna[2].size() << endl;
    
    Sequence DNA_Array[3];
    
    //initialize DNA_Array;
    for (int geneNumber = 0; geneNumber != 3; ++geneNumber) {
        DNA_Array[geneNumber].initializeGeneSequence(dna[geneNumber], geneNumber, dna_size[geneNumber]);
        DNA_Array[geneNumber].translation();
    }
    
    int m_size = 2;
    double old_grn[170][170];
    for (int i = 0; i != 170; ++i) {
        for (int j = 0; j != 170; ++j) {
            old_grn[i][j] = 2;
        }
    }
    old_grn[0][0] = 0;
    old_grn[0][1] = -1;
    old_grn[1][0] = 1;
    old_grn[1][1] = 2;
    
    GRN test_GRN;
    test_GRN.initializeGRN(old_grn, m_size);
    test_GRN.constructNewGRN(DNA_Array);
    for (int i = 0; i != 5; ++i) {
        for (int j = 0; j != 5; ++j) {
            cout << test_GRN.newGRNCorrelation[i][j] << '\t';
        }
        cout << endl;
    }
}

