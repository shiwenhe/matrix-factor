//-*- mode: c++ -*-
#ifndef _LIL_MATRIX_SYM_PERM_H_
#define _LIL_MATRIX_SYM_PERM_H_

template<class el_type>
void lilc_matrix<el_type> :: sym_perm(std::vector<int>& perm) {
	vector<idx_vector_type> m_idx_new(m_n_cols);
	vector<elt_vector_type> m_x_new(m_n_cols);
	
	int i, j, pi, pj;
	el_type px;
	for (i = 0; i < m_n_cols; i++) { //no need to use function call n_cols() every iter
		pj = perm[i];
		
		for (j = 0; j < (int) m_idx[i].size(); j++) {
			pi = perm[m_idx[i][j]];
			px = m_x[i][j];
			
			if (pi < pj) {
				m_idx_new[ pi ].push_back(pj);
				m_x_new[ pi ].push_back(px);
				
			} else {
				m_idx_new[ pj ].push_back(pi);
				m_x_new[ pj ].push_back(px);
				
			}
		}
	}
	
	m_idx.swap(m_idx_new);
	m_x.swap(m_x_new);
	
	for (i = 0; i < m_n_cols; i++) {
		ensure_invariant(i, i, m_idx[i], 0);
	}
}

#endif // _LIL_MATRIX_SYM_PERM_H_