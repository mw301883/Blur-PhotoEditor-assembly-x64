.data
	avg dd 0
	;v1 dd rcx
	;v2 dd rdx
	;v3 dd r8
	;v4 dd r9
	;v5 dd [rsp + 8]
	;v6 dd [rsp + 9]
	;v7 dd [rsp + 10]
	;v8 dd [rsp + 11]
	;v9 dd [rsp + 12]

	;w1 dd [rsp + 13]
	;w2 dd [rsp + 14]
	;w3 dd [rsp + 15]
	;w4 dd [rsp + 16]
	;w5 dd [rsp + 17]
	;w6 dd [rsp + 18]
	;w7 dd [rsp + 19]
	;w8 dd [rsp + 20]
	;w9 dd [rsp + 21]
.code
wavg_calc_asm proc
    
	;zapis parametr�w v1, v2, v3, v4 do rejestru xmm0

	movd xmm0, ecx ;przeniesnie parametru v1 (pierwszy argument) do xmm0
	movd xmm1, edx ;przeniesnie parametru v2 (drugi argument) do xmm1
	punpckldq xmm0, xmm1 ;po��czenie dolnych po��wek rejestr�w xmm0 i xmm1
	pslldq xmm0, 8 ;przesuni�cie bitowe o warto�� 64 bit�w (exc i edx)
	movq xmm1, r8  ;wpis parametru v3 do rejestru xmm1
	movq xmm2, r9  ;wpis parametru v4 do rejestru xmm1
	punpckldq xmm1, xmm2 ;po��czenie dolnych po��wek rejestr�w xmm1 i xmm2
	addsd xmm0, xmm1 ;po��czenie parametr�w v1, v2, v3, v4 w jednym rejestrze xmm0

	;zapis parametr�w w1, w2, w3, w4 do rejestru xmm1 TODO

	movd xmm0, ecx ;przeniesnie parametru v1 (pierwszy argument) do xmm0
	movd xmm1, edx ;przeniesnie parametru v2 (drugi argument) do xmm1
	punpckldq xmm0, xmm1 ;po��czenie dolnych po��wek rejestr�w xmm0 i xmm1
	pslldq xmm0, 8 ;przesuni�cie bitowe o warto�� 64 bit�w (exc i edx)
	movq xmm1, r8  ;wpis parametru v3 do rejestru xmm1
	movq xmm2, r9  ;wpis parametru v4 do rejestru xmm1
	punpckldq xmm1, xmm2 ;po��czenie dolnych po��wek rejestr�w xmm1 i xmm2
	addsd xmm0, xmm1 ;po��czenie parametr�w v1, v2, v3, v4 w jednym rejestrze xmm0

	ret
wavg_calc_asm endp
end
