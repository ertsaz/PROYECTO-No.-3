int dividir(int nIni, int nFin, int nPivote, int *arrNumeros, int *nInter)
{
   int nPunto_Ini = nIni - 1;
   int nPunto_Final = nFin;

   while (1)
   {
      while (arrNumeros[++nPunto_Ini] < nPivote)
      {
      }

      while (nPunto_Final > 0 && arrNumeros[--nPunto_Final] > nPivote)
      {
      }

      if (nPunto_Ini >= nPunto_Final)
      {
         break;
      }
      else
      {
         swap(nPunto_Ini, nPunto_Final, arrNumeros);
         //*nInter += 1;
      }
   }
   swap(nPunto_Ini, nFin, arrNumeros);
   *nInter += 1;;

   return nPunto_Ini;
}

void quickSort(int nIni, int nFin, int *arrNumeros, int *nInter)
{
   if (nFin - nIni <= 0)
   {
      return;
   }
   else
   {
      int nPivote = arrNumeros[nFin];
      int nPunto_divicion = dividir(nIni, nFin, nPivote, arrNumeros, nInter);
      quickSort(nIni, nPunto_divicion - 1, arrNumeros, nInter);
      quickSort(nPunto_divicion + 1, nFin, arrNumeros, nInter);
   }
}