	
.code
wavg_calc_asm proc

	;zapis parametrów v1, v2, v3, v4 do rejestru zmm0

	vmovupd zmm0, zmmword ptr [rcx]		;pobranie parametrów piksela
	vmovupd zmm1, zmmword ptr [rdx]		;pobranie wag
	VPMADDWD zmm0, zmm0, zmm1			;wymno¿enie parametrów przez wagi
	vextractf64x4 ymm2, zmm0, 1			;suma iloczynów
	vaddpd ymm0, ymm2, ymm0
	VEXTRACTF32X4 xmm2, ymm0, 1
	vaddpd xmm0, xmm2, xmm0
	vpmovzxwd xmm2, xmm0 
	PSRLDQ xmm0, 8
	vpmovzxwd xmm0, xmm0
	vaddpd xmm0, xmm2, xmm0
	vmovupd xmm2, xmm0
	PSRLDQ xmm0, 8
	vaddpd xmm0, xmm2, xmm0
	movd eax, xmm0

	;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
	vextractf64x4 ymm2, zmm1, 1			;suma wag
	vaddpd ymm1, ymm2, ymm1
	VEXTRACTF32X4 xmm2, ymm1, 1
	vaddpd xmm1, xmm2, xmm1
	vpmovzxwd xmm2, xmm1
	PSRLDQ xmm1, 8
	vpmovzxwd xmm1, xmm1
	vaddpd xmm1, xmm2, xmm1
	vmovupd xmm2, xmm1
	PSRLDQ xmm1, 8
	vaddpd xmm1, xmm2, xmm1
	movd ecx, xmm1

	xor edx, edx      ; Wyczyszczenie rejestru edx

    ; Dzielenie eax przez ecx
    div ecx				;wykonanie dzielenia rejestrów eax / ecx

	ret
wavg_calc_asm endp
end
