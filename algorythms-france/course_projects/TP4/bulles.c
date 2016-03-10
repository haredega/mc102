void permuter(t_VectAllumettes Allumettes, int i_changer){
     t_Allumette aux;
     
     aux = Allumettes[i_changer];

     Allumettes[i_changer] = Allumettes[i_changer+1];
     Allumettes[i_changer+1] = aux;

     return;
}