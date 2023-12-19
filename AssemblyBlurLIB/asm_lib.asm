	
.code
wavg_calc_asm proc

	;suma iloczyn�w parametr�w i wag

	vmovupd zmm0, zmmword ptr [rcx]		;pobranie parametr�w piksela
	vmovupd zmm1, zmmword ptr [rdx]		;pobranie wag
	VPMADDWD zmm0, zmm0, zmm1			;wymno�enie horyzontalne parametr�w przez wagi
	vextractf64x4 ymm2, zmm0, 1			;przeniesienie g�rnej po��wki rejestru zmm0 do rejestru ymm0
	vaddpd ymm0, ymm2, ymm0				;suma horyzontalna rejestr�w ymm0 i ymm2
	VEXTRACTF32X4 xmm2, ymm0, 1			;przeniesienie zawarto�ci g�rnej po��wki rejestru ymm0 do xmm2
	vaddpd xmm0, xmm2, xmm0				;suma horyzontalna rejestr�w xmm0 i xmm2
	vpmovzxwd xmm2, xmm0				;przeniesienie rejestru xmm0 do xmm2
	PSRLDQ xmm0, 8						;przesuni�cie rejestru xmm0 o 8 bajt�w (2 integery)
	vpmovzxwd xmm0, xmm0				;rozsuni�cie po��wek (czyli 2 razy po 4 bajty - int) dolnego rejestru xmm0 do g�rnej i dolnej cz�ci xmm0 i zapis w xmm0
	vaddpd xmm0, xmm2, xmm0				;suma horyzontalna rejestr�w xmm0 i xmm2
	vmovupd xmm2, xmm0					;przeniesienie zawarto�ci g�rnej po��wki rejestru xmm0 do xmm2
	PSRLDQ xmm0, 8						;przesuni�cie rejestru xmm0 o 8 bajt�w (2 integery)
	vaddpd xmm0, xmm2, xmm0				;horyzontalna suma rejestr�w xmm0 i xmm2 (dodanie dw�ch ostatnich sk�adowych sumy iloczyn�w)
	movd eax, xmm0						;przeniesienie wyniku do rejestru  eax (rejestr w kt�rym zwracany jest wynik funkcji)

	;suma wag

	vextractf64x4 ymm2, zmm1, 1			;przeniesienie g�rnej po��wki rejestru zmm1 do rejestru ymm2
	vaddpd ymm1, ymm2, ymm1				;suma horyzontalna rejestr�w ymm1 i ymm2
	VEXTRACTF32X4 xmm2, ymm1, 1			;przeniesienie zawarto�ci g�rnej po��wki rejestru ymm1 do xmm2
	vaddpd xmm1, xmm2, xmm1				;suma horyzontalna rejestr�w xmm1 i xmm2
	vpmovzxwd xmm2, xmm1				;przeniesienie rejestru xmm1 do xmm2
	PSRLDQ xmm1, 8						;przesuni�cie rejestru xmm1 o 8 bajt�w (2 integery)
	vpmovzxwd xmm1, xmm1				;rozsuni�cie po��wek (czyli 2 razy po 4 bajty - int) dolnego rejestru xmm1 do g�rnej i dolnej cz�ci xmm1 i zapis w xmm1
	vaddpd xmm1, xmm2, xmm1				;suma horyzontalna rejestr�w xmm1 i xmm2
	vmovupd xmm2, xmm1					;przeniesienie zawarto�ci g�rnej po��wki rejestru xmm1 do xmm2
	PSRLDQ xmm1, 8						;przesuni�cie rejestru xmm1 o 8 bajt�w (2 integery)
	vaddpd xmm1, xmm2, xmm1				;horyzontalna suma rejestr�w xmm0 i xmm2 (dodanie dw�ch ostatnich sk�adowych sumy wag)
	movd ecx, xmm1						;przeniesienie wyniku do rejestru ecx w celu dokonania dzielenia rejestru eax

	xor edx, edx      ; Wyczyszczenie rejestru edx

    ; Dzielenie eax przez ecx
    div ecx				;wykonanie dzielenia rejestr�w eax / ecx --> czyli dzielenie sumy iloczyn�w parametr�w i wag przez sum� wag

	ret
wavg_calc_asm endp
end
