

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
#define MAX_ELEMENTS 40
int srch_st(char* strs[MAX_ELEMENTS], char *s, int num){
    int ii;
    for (ii=0; ii<num; ii++){
        if (!strcmp(strs[ii],s))
            return ii+1;
    }
    return 0;
}


int find (int *rt, double wt[][MAX_ELEMENTS], int x){
    int rx = rt[x];
    if (rx == x){
        return x;
    }
    rt[x] = find(rt, wt, rx);
    if (rt[x] != rx) {
        wt[x][rt[x]] = wt[x][rx] * wt[rx][rt[x]];
        wt[rt[x]][x] = 1/(wt[x][rt[x]]);

    }
    return (rt[x]);
}

void ulink(int *rt, int *rnk, double wt[][MAX_ELEMENTS], double w, int x, int y){
    int rx, ry;
    rx = find(rt, wt, x);
    ry = find(rt, wt, y);
    wt[x][y] = w;
    wt[y][x] = 1/w;
    if (rx == ry) return;
    wt[rx][ry] = wt[rx][x] * wt[y][ry] *wt[x][y];
    wt[ry][rx] = 1/(wt[rx][ry]);
    if (rnk[rx] > rnk[ry]){
        rt[ry] = rx;
    }else if (rnk[ry] > rnk[rx]){
        rt[rx] = ry;
    }else{
        rt[ry] = rx;
        rnk[rx] += 1;
    }

    return;
}

double* calcEquation(char *** equations, int equationsSize, int* equationsColSize, double* values, int valuesSize, char *** queries, int queriesSize, int* queriesColSize, int* returnSize){
    int num_strs=0;
    char *strs[MAX_ELEMENTS];
    int rt[MAX_ELEMENTS];
    char *s;
    int id1, id2;
    double wt[MAX_ELEMENTS][MAX_ELEMENTS];
    {
        int rnk[MAX_ELEMENTS];
        for (int ii=0; ii< MAX_ELEMENTS; ii++){
                for (int jj=0; jj< MAX_ELEMENTS; jj++)
                    wt[ii][jj] = 1.0;
                rt[ii]  =ii;
                rnk[ii] = 1;
        }
        for (int ii=0; ii< equationsSize; ii++){
            /* get each string */
            s =  equations[ii][0];
            if (!(id1 = srch_st(strs, s, num_strs))){
                strs[num_strs] = s;
                id1 = num_strs;
                num_strs++;
            }else  id1--;
            s =  equations[ii][1];
            if (!(id2 = srch_st(strs, s, num_strs))){
                strs[num_strs] = s;
                id2 = num_strs;
                num_strs++;
            }else id2--;
            ulink(rt, rnk, wt, values[ii], id1, id2);
        }
    }
    double *res = (double *) malloc(sizeof(double) * queriesSize);

    for (int ii=0; ii<queriesSize; ii++){
        s = queries[ii][0];
        if (!(id1 = srch_st(strs, s, num_strs))){
            res[ii] = -1;
            continue;
        }else id1--;
        s = queries[ii][1];
        if (!(id2 = srch_st(strs, s, num_strs))){
            res[ii] = -1;
            continue;
        }else id2--;
        if (id1 == id2){
            res[ii] = 1;
        }

        else if (wt[id1][id2] != 1.0)
            res[ii] = wt[id1][id2];
        else {
            int rx =  find(rt, wt, id1);
            int ry = find (rt, wt, id2);
            if (rx == ry){
                res[ii] = wt[id1][rx] * wt[rx][id2];
            } else
                res[ii] = -1.0;
        }
    }
    *returnSize = queriesSize;
    return res;
}