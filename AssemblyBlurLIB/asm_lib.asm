	
.code
wavg_calc_asm proc
    
	;zapis parametrów v1, v2, v3, v4 do rejestru xmm0

	movd xmm0, ecx ;przeniesnie parametru v1 (pierwszy argument) do xmm0
	movd xmm1, edx ;przeniesnie parametru v2 (drugi argument) do xmm1
	punpckldq xmm0, xmm1 ;po³¹czenie dolnych po³ówek rejestrów xmm0 i xmm1
	pslldq xmm0, 8 ;przesuniêcie bitowe o wartoœæ 64 bitów (exc i edx)
	movd xmm1, r8  ;wpis parametru v3 do rejestru xmm1
	movd xmm2, r9  ;wpis parametru v4 do rejestru xmm2
	punpckldq xmm1, xmm2 ;po³¹czenie dolnych po³ówek rejestrów xmm1 i xmm2
	addsd xmm0, xmm1 ;po³¹czenie parametrów v1, v2, v3, v4 w jednym rejestrze xmm0

	;zapis parametrów w1, w2, w3, w4 do rejestru xmm1

	movd xmm1, dword ptr [rsp + 80] ;przeniesnie parametru w1 do xmm1
	mov ecx, dword ptr [rsp + 80] ;pobranie w1 do rejestru exc (bêdzie tam przechowywana suma wag)
	movd xmm2, dword ptr [rsp + 88] ;przeniesnie parametru w2 do xmm2
	add ecx, dword ptr [rsp + 88] ;dodanie do rejestru ecx w2
	punpckldq xmm1, xmm2 ;po³¹czenie dolnych po³ówek rejestrów xmm1 i xmm2
	pslldq xmm1, 8 ;przesuniêcie bitowe o wartoœæ 64 bitów
	movd xmm2, dword ptr [rsp + 96] ;wpis parametru w3 do rejestru xmm2
	add ecx, dword ptr [rsp + 96] ;dodanie do rejestru ecx w3
	movd xmm3, dword ptr [rsp + 104] ;wpis parametru w4 do rejestru xmm3
	add ecx, dword ptr [rsp + 104] ;dodanie do rejestru ecx w4
	punpckldq xmm2, xmm3 ;po³¹czenie dolnych po³ówek rejestrów xmm2 i xmm3
	addsd xmm1, xmm2 ;po³¹czenie parametrów w1, w2, w3, w4 w jednym rejestrze xmm1

	pmaddwd xmm0, xmm1 ;wymno¿enie wartoœci v1, v2, v3, v4 i wag w1, w2, w3, w4

	;zapisanie wyniku do rejestru xmm4
	movaps xmm4, xmm0

	;TODO dalsza zabawa ...

	;zapis parametrów v5, v6, v7, v8 do rejestru xmm0

	movd xmm0, dword ptr [rsp + 40] ;przeniesnie parametru v5 (pierwszy argument) do xmm0
	movd xmm1, dword ptr [rsp + 48] ;przeniesnie parametru v6 (drugi argument) do xmm1
	punpckldq xmm0, xmm1 ;po³¹czenie dolnych po³ówek rejestrów xmm0 i xmm1
	pslldq xmm0, 8 ;przesuniêcie bitowe o wartoœæ 64 bitów
	movd xmm1, dword ptr [rsp + 56]  ;wpis parametru v7 do rejestru xmm1
	movd xmm2, dword ptr [rsp + 64]  ;wpis parametru v8 do rejestru xmm2
	punpckldq xmm1, xmm2 ;po³¹czenie dolnych po³ówek rejestrów xmm1 i xmm2
	addsd xmm0, xmm1 ;po³¹czenie parametrów v5, v6, v7, v8 w jednym rejestrze xmm0

	;zapis parametrów w5, w6, w7, w8 do rejestru xmm1

	movd xmm1, dword ptr [rsp + 112] ;przeniesnie parametru w5 do xmm1
	add ecx, dword ptr [rsp + 112] ;dodanie do rejestru ecx w5
	movd xmm2, dword ptr [rsp + 120] ;przeniesnie parametru w6 do xmm2
	add ecx, dword ptr [rsp + 120] ;dodanie do rejestru ecx w6
	punpckldq xmm1, xmm2 ;po³¹czenie dolnych po³ówek rejestrów xmm1 i xmm2
	pslldq xmm1, 8 ;przesuniêcie bitowe o wartoœæ 64 bitów
	movd xmm2, dword ptr [rsp + 128] ;wpis parametru w7 do rejestru xmm2
	add ecx, dword ptr [rsp + 128] ;dodanie do rejestru ecx w7
	movd xmm3, dword ptr [rsp + 136] ;wpis parametru w8 do rejestru xmm3
	add ecx, dword ptr [rsp + 136] ;dodanie do rejestru ecx w8
	punpckldq xmm2, xmm3 ;po³¹czenie dolnych po³ówek rejestrów xmm2 i xmm3
	addsd xmm1, xmm2 ;po³¹czenie parametrów w1, w2, w3, w4 w jednym rejestrze xmm1

	pmaddwd xmm0, xmm1 ;wymno¿enie wartoœci v5, v6, v7, v8 i wag w5, w6, w7, w8
	
	mov eax, dword ptr [rsp + 72] ;pobranie v9 do rejestru eax (rejestr z wynikiem)
	mov ebx, dword ptr [rsp + 144] ;pobranie w9 do rejestru ebx
	add ecx, dword ptr [rsp + 144] ;dodanie do rejestru ecx w9
	imul eax, ebx ;wymno¿enie v9 z w9 i zapisanie wyniku w rejestrze eax

	;dodanie wymno¿onych sk³adników œredniej wa¿onej do rejestru eax (rejestr z wynikiem)

	movd ebx, xmm4 ;pobranie v1*w1 do rejestru ebx
	add eax, ebx ;dodanie v1*w1 do rejestru eax
	PSRLDQ xmm4, 4 ;przesuniêcie o 4 bity w prawo w rejesrze xmm4
	movd ebx, xmm4 ;pobranie v2*w2 do rejestru ebx
	add eax, ebx ;dodanie v2*w2 do rejestru eax
	PSRLDQ xmm4, 4 ;przesuniêcie o 4 bity w prawo w rejesrze xmm4
	movd ebx, xmm4 ;pobranie v3*w3 do rejestru ebx
	add eax, ebx ;dodanie v3*w3 do rejestru eax
	PSRLDQ xmm4, 4 ;przesuniêcie o 4 bity w prawo w rejesrze xmm4
	movd ebx, xmm4 ;pobranie v4*w4 do rejestru ebx
	add eax, ebx ;dodanie v4*w4 do rejestru eax
	
	movd ebx, xmm0 ;pobranie v5*w5 do rejestru ebx
	add eax, ebx ;dodanie v5*w5 do rejestru eax
	PSRLDQ xmm0, 4 ;przesuniêcie o 4 bity w prawo w rejesrze xmm4
	movd ebx, xmm0 ;pobranie v6*w6 do rejestru ebx
	add eax, ebx ;dodanie v6*w6 do rejestru eax
	PSRLDQ xmm0, 4 ;przesuniêcie o 4 bity w prawo w rejesrze xmm4
	movd ebx, xmm0 ;pobranie v7*w7 do rejestru ebx
	add eax, ebx ;dodanie v7*w7 do rejestru eax
	PSRLDQ xmm0, 4 ;przesuniêcie o 4 bity w prawo w rejesrze xmm4
	movd ebx, xmm0 ;pobranie v8*w8 do rejestru ebx
	add eax, ebx ;dodanie v8*w8 do rejestru eax

	xor edx, edx      ; Wyczyszczenie rejestru edx

    ; Dzielenie eax przez ecx
    div ecx ;wykonanie dzielenia rejestrów eax / ecx --> (v1*w1 + ... + v1*w9) / (w1 + ... w9)

	ret
wavg_calc_asm endp
end
