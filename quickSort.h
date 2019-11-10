int dividir(int nIni, int nFin, int nPivote, int *arrNumeros)
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
      }
   }
   swap(nPunto_Ini, nFin, arrNumeros);
   return nPunto_Ini;
}

void quickSort(int nIni, int nFin, int *arrNumeros)
{
   if (nFin - nIni <= 0)
   {
      return;
   }
   else
   {
      int nPivote = arrNumeros[nFin];
      int nPunto_divicion = dividir(nIni, nFin, nPivote, arrNumeros);
      quickSort(nIni, nPunto_divicion - 1, arrNumeros);
      quickSort(nPunto_divicion + 1, nFin, arrNumeros);
   }
}