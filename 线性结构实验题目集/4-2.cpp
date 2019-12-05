int Isomorphic( Tree T1, Tree T2 ) {
	if(T1==NULL&&T2==NULL)
		return 1;
	else if(T1==NULL||T2==NULL)
		return 0;
	else if(T1->Element!=T2->Element)
		return 0;
	else if(T1->Element==T2->Element) 
			return Isomorphic(T1->Left,T2->Left)&&Isomorphic(T1->Right,T2->Right)||Isomorphic(T1->Left,T2->Right)&&Isomorphic(T1->Right,T2->Left); 
}