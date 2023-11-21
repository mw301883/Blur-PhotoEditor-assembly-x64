.data
	avg dd 0
	
.code
wavg_calc_asm proc
    
	;zapis parametrów v1, v2, v3, v4 do rejestru xmm0

	movd xmm0, ecx ;przeniesnie parametru v1 (pierwszy argument) do xmm0
	movd xmm1, edx ;przeniesnie parametru v2 (drugi argument) do xmm1
	punpckldq xmm0, xmm1 ;po³¹czenie dolnych po³ówek rejestrów xmm0 i xmm1
	pslldq xmm0, 8 ;przesuniêcie bitowe o wartoœæ 64 bitów (exc i edx)
	movq xmm1, r8  ;wpis parametru v3 do rejestru xmm1
	movq xmm2, r9  ;wpis parametru v4 do rejestru xmm2
	punpckldq xmm1, xmm2 ;po³¹czenie dolnych po³ówek rejestrów xmm1 i xmm2
	addsd xmm0, xmm1 ;po³¹czenie parametrów v1, v2, v3, v4 w jednym rejestrze xmm0

	;zapis parametrów w1, w2, w3, w4 do rejestru xmm1

	movd xmm1, dword ptr [rsp + 80] ;przeniesnie parametru w1 do xmm1
	movd xmm2, dword ptr [rsp + 88] ;przeniesnie parametru w2 do xmm2
	punpckldq xmm1, xmm2 ;po³¹czenie dolnych po³ówek rejestrów xmm1 i xmm2
	pslldq xmm1, 8 ;przesuniêcie bitowe o wartoœæ 64 bitów
	movd xmm2, dword ptr [rsp + 96] ;wpis parametru w3 do rejestru xmm2
	movd xmm3, dword ptr [rsp + 104] ;wpis parametru w4 do rejestru xmm3
	punpckldq xmm2, xmm3 ;po³¹czenie dolnych po³ówek rejestrów xmm2 i xmm3
	addsd xmm1, xmm2 ;po³¹czenie parametrów v1, v2, v3, v4 w jednym rejestrze xmm1

	;TODO dalsza zabawa ...

	ret
wavg_calc_asm endp
end
