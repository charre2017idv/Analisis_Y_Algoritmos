#define _CRT_SECURE_NO_WARNINGS
// TEMA:
#include<iostream>
#include <ctime>
#include <chrono>
#include <string>
using namespace std;
string obtener_secuencias(string sec, int num);
string compararSubsecuencias(string subsecuencias1, string subsecuencias2);;
int main()
{
//   string secuencia1 = "agtgagctccggagtatttcaggaccggcttgattagggtgcttactacccagttgtggatctttaaggactttttgcagtgaccacaagtgtatagtcttgatagccgctggttctcgagttactcaaggcaagggccaattttggtccgggcagaagacgcgttatccctgtcatctgttatatcccgtctgagaagcggctcggggcggatagtgctcccgactcaacaccacaccggtagccctaacgcagagctgtcctaaataacttccgtcgtcatcacgacgctcatataggcggtatgtccgggtctctggatttgatagggattgaccgctactcggccatggaaaacttaggttacttaccgttgtatccagtatctggtctgtccccagattgtcaataaggctggaatttgatgaataggtctaacaacacataaagcgtgtggaggcggacgacatagacttaagatcactccgacctgtctcatctccctttcttcatttggagtactactaagtttcggctgcgtaccatacaagacaagcatgttcaccgcagtgtataggtgtatcactttgaatgcgaggctggtggctatcaaggtatcatagtgagctacactgacattcatacttcaaacctcctcttggaatgccgggaataggtacgctaacgaagggcccgcagccgatggcgggtaagggattactcatcctccgagctaagaagagtggaggctaacagattccttctaaagcctcccaggtttttcgttatgaatagttcgaggggtgcagtgtttccgtccgcggggaccgcgacggtagctatatgtttccggcttcactttgaaccgggcccgactcccgacaacccaaaagcattgttcaaggccgcagtcctatcgcatcgactcacgcctcgaccatgcgcctccacttagttccagaaacattgaagaatccagcccgtggtgttgctctagtta"; //#Primera secuencia
//   string secuencia2 = "cagatcttggtctattatgacgaaggcgggttacgaggttataacactggcgcagtaaagctcacgtcgcatgctcagcaacaggaagattttctgtgtacatttgcagtttatgtcgagccgcgtggactgatctcgaatacgtaaattgtcccgcctccacctgagttttagaagagagaatacttaaggttgactaatcagcggagctaactgaagccgcctgttgaggctgttactggcgtcttgctggacactgattgagtcccagcctgacgtggtaccttgtagctcttgctgatcgtgcccctaaaaattaccacggcggtggagcaaacttctctggaacactgccgctctcctagtgagtacttttcaacgtcattatctggcagtagcttcagttctcatctattcagcgctgagccacgttccaagggcctgtttagacattgaagatttatgtgccttgtctttttataatatatgggagccggagttccacgggcgttcgtaatcactggttacaacaatgcagagagcacagtatatcactgcgctatcttaagtttgactaagaagccctaaagcactttaaaatacgcatggtcctcttcttgtggtcttcctcaagatgtcgagaagccatgcaacttaaggcgatgagaggtgacgtttgtcctataaatgcgaaatctctgctgcctgctgttaggctccccaaagagcaccagagtgtgggtataagtttcgtcatcccttcaatatctcacgttttcaaaaatttagttcaggtggtcgctctttctcgcgcgagcttcacgacgcattacggtcagcgataggcatggatatgcccaagcaaacgtaggatcatcctccattcaaaaaccgaagcggccaagatacagtagtttccctatccccgcatggggcttgttctgtggtggaactcaatcctgggaatgatagtcgacgcagtgcaggtgacgcgagtgca";// #Segunda secuencia
 // string secuencia1 = "gcttgctcctagtatctccaccggtcttagataccgcaaattgtatttttgcaggccaatgtatcgtttcgtccgcaccttagtataaaagaggattcaa";
 // string secuencia2 = "tggttgtgaaagcgacgttcgtaccctggacagccgcctgcaattaaggcatacagtgggtccggtccatcgtccgcacaaacttgcctcaaagtaaagg";
  string secuencia1 = "TTCGCATCGGGTTG";
  string secuencia2 = "TGACCGTGTGTCACG";
  string subsecuencias1 = obtener_secuencias(secuencia1,1);// #Obtiene todas las subsecuencias de la secuencia 1
  string subsecuencias2 = obtener_secuencias(secuencia2,2);// #Obtiene todas las subsecuencias de la secuencia 2

  // Compare time
  chrono::time_point<chrono::system_clock> start, end;
  start = chrono::system_clock::now();
  string lcs = compararSubsecuencias(subsecuencias1, subsecuencias2);
  end = chrono::system_clock::now();
  int elapsed_seconds = chrono::duration_cast<chrono::seconds>
    (end - start).count();
  time_t end_time = chrono::system_clock::to_time_t(end);

  cout << "---- BRUTE FORCE ----" << endl;
  cout << "La subsecuencia mas larga comun de " << secuencia1 << " y de " << secuencia2 << " es " << lcs << endl;
  cout << "Cálculo terminado  " << ctime(&end_time) << "tiempo transcurrido: " << elapsed_seconds << "s\n";
  cin.ignore();
  cin.get();
  return 0;
}

string obtener_secuencias(string sec, int num)
{
  int n = sec.size();
  int numSubsecuencias = 2^n;
  string subs;
  for (int i = 1; i < numSubsecuencias; i++)
  {
    string subsecuence;
    for (int j = 0; j < n; j++)
    {
      if (i && (1<<j))
      {
        subsecuence += sec[i];
      }
    }
    subs += subsecuence;
  }
  return subs;
}

string compararSubsecuencias(string subsecuencias1, string subsecuencias2)
{
  string lcs;
  for (int i = 0; i < subsecuencias1.size(); i++)
  {
    for (int j = 0; j < subsecuencias2.size(); j++)
    {
      if (subsecuencias1[i] == subsecuencias2[j])
      {
        if (lcs.size() < subsecuencias1.size())
        {
          lcs = subsecuencias1[i];
        }
      }
    }
  }
  return lcs;
}


// TEMA:
// #include<iostream>
// using namespace std;
// 
// void lcs(string X, string Y, int m, int n)
// {
//   int L[][]
// }
// 
// int main()
// {
//   cin.ignore();
//   cin.get();
//   return 0;
// }

