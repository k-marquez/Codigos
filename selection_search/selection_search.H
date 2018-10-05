#ifndef SELECTION_SEARCH_H
#define SELECTION_SEARCH_H

template <class T, class C>
void SelectionSearch( T * a, unsigned int n, const C & c)
{
	for (int i = 0 ; i < (n - 1)  ; ++i)
	{
		int j;
		for (j=i; j < n  ; ++j)
		{
			if (c(a->at(i) , a->at(j)))
			{
				std::swap(a->at(j),a->at(i));
			}
		}
	}
}

#endif	// SELECTION_SEARCH_H