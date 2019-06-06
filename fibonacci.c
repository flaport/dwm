void
fibonacci(Monitor *mon) {
	unsigned int i, n, nx, ny, nw, nh, ng;
	Client *c;

	for(n = 0, c = nexttiled(mon->clients); c; c = nexttiled(c->next), n++);
	if(n == 0)
		return;
	
    ng = 0.5 * gappx;
	nx = mon->wx;
	ny = 100;
	nw = mon->ww;
	nh = mon->wh;
	
	for(i = 0, c = nexttiled(mon->clients); c; c = nexttiled(c->next)) {
		if((i % 2 && nh / 2 > 2 * c->bw) || (!(i % 2) && nw / 2 > 2 * c->bw)) {
			if(i < n - 1) {
				if(i % 2)
					nh /= 2;
				else
					nw /= 2;
			}
			if((i % 4) == 0) {
                ny += nh;
			}
			else if((i % 4) == 1)
				nx += nw;
			else if((i % 4) == 2)
				ny += nh;
			else if((i % 4) == 3) {
                nx += nw;
			}
			if(i == 0)
			{
				if(n != 1)
					nw = mon->ww * mon->mfact;
				ny = mon->wy;
			}
			else if(i == 1)
				nw = mon->ww - nw;
			i++;
		}

        if ((nw - 2 * c->bw < 2 * ng) || (nh - 2 * c->bw < 2 * ng)){
            ng = 0;
        } else {
            ng = 0.5 * gappx;
        }

		resize(c, nx+ng, ny+ng, nw - 2 * c->bw - 2 * ng, nh - 2 * c->bw - 2 * ng, False);
	}
}
