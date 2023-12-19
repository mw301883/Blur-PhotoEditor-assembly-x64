	
.code
wavg_calc_asm proc

	;suma iloczynów parametrów i wag

	vmovupd zmm0, zmmword ptr [rcx]		;pobranie parametrów piksela
	vmovupd zmm1, zmmword ptr [rdx]		;pobranie wag
	VPMADDWD zmm0, zmm0, zmm1			;wymno¿enie horyzontalne parametrów przez wagi
	vextractf64x4 ymm2, zmm0, 1			;przeniesienie górnej po³ówki rejestru zmm0 do rejestru ymm0
	vaddpd ymm0, ymm2, ymm0				;suma horyzontalna rejestrów ymm0 i ymm2
	VEXTRACTF32X4 xmm2, ymm0, 1			;przeniesienie zawartoœci górnej po³ówki rejestru ymm0 do xmm2
	vaddpd xmm0, xmm2, xmm0				;suma horyzontalna rejestrów xmm0 i xmm2
	vpmovzxwd xmm2, xmm0				;przeniesienie rejestru xmm0 do xmm2
	PSRLDQ xmm0, 8						;przesuniêcie rejestru xmm0 o 8 bajtów (2 integery)
	vpmovzxwd xmm0, xmm0				;rozsuniêcie po³ówek (czyli 2 razy po 4 bajty - int) dolnego rejestru xmm0 do górnej i dolnej czêœci xmm0 i zapis w xmm0
	vaddpd xmm0, xmm2, xmm0				;suma horyzontalna rejestrów xmm0 i xmm2
	vmovupd xmm2, xmm0					;przeniesienie zawartoœci górnej po³ówki rejestru xmm0 do xmm2
	PSRLDQ xmm0, 8						;przesuniêcie rejestru xmm0 o 8 bajtów (2 integery)
	vaddpd xmm0, xmm2, xmm0				;horyzontalna suma rejestrów xmm0 i xmm2 (dodanie dwóch ostatnich sk³adowych sumy iloczynów)
	movd eax, xmm0						;przeniesienie wyniku do rejestru  eax (rejestr w którym zwracany jest wynik funkcji)

	;suma wag

	vextractf64x4 ymm2, zmm1, 1			;przeniesienie górnej po³ówki rejestru zmm1 do rejestru ymm2
	vaddpd ymm1, ymm2, ymm1				;suma horyzontalna rejestrów ymm1 i ymm2
	VEXTRACTF32X4 xmm2, ymm1, 1			;przeniesienie zawartoœci górnej po³ówki rejestru ymm1 do xmm2
	vaddpd xmm1, xmm2, xmm1				;suma horyzontalna rejestrów xmm1 i xmm2
	vpmovzxwd xmm2, xmm1				;przeniesienie rejestru xmm1 do xmm2
	PSRLDQ xmm1, 8						;przesuniêcie rejestru xmm1 o 8 bajtów (2 integery)
	vpmovzxwd xmm1, xmm1				;rozsuniêcie po³ówek (czyli 2 razy po 4 bajty - int) dolnego rejestru xmm1 do górnej i dolnej czêœci xmm1 i zapis w xmm1
	vaddpd xmm1, xmm2, xmm1				;suma horyzontalna rejestrów xmm1 i xmm2
	vmovupd xmm2, xmm1					;przeniesienie zawartoœci górnej po³ówki rejestru xmm1 do xmm2
	PSRLDQ xmm1, 8						;przesuniêcie rejestru xmm1 o 8 bajtów (2 integery)
	vaddpd xmm1, xmm2, xmm1				;horyzontalna suma rejestrów xmm0 i xmm2 (dodanie dwóch ostatnich sk³adowych sumy wag)
	movd ecx, xmm1						;przeniesienie wyniku do rejestru ecx w celu dokonania dzielenia rejestru eax

	xor edx, edx      ; Wyczyszczenie rejestru edx

    ; Dzielenie eax przez ecx
    div ecx				;wykonanie dzielenia rejestrów eax / ecx --> czyli dzielenie sumy iloczynów parametrów i wag przez sumê wag

	ret
wavg_calc_asm endp
end
