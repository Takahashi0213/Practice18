Texture2D	g_texture		: register(t0);
sampler2D	g_sampler		: register(s0);

Texture2D		g_backTexture		: register(t1);
SamplerState	g_backSampler		: register(s1);

float4		g_scale			: register(c0);
float4 mUVInversedBack		: register(c1);

struct PS_Input
{
	float2 UV		: TEXCOORD0;
	float4 Normal		: TEXCOORD1;
	float4 Binormal		: TEXCOORD2;
	float4 Tangent		: TEXCOORD3;
	float4 Pos			: TEXCOORD4;
	float4 Color		: COLOR;
};

float4 PS( const PS_Input Input ) : COLOR
{
#ifdef ENABLE_COLOR_TEXTURE
	float4 Output = tex2D(g_sampler, Input.UV);
#else
	float4 Output = float4(1.0, 1.0, 1.0, 1.0);
#endif
	Output.a = Output.a * Input.Color.a;

	if (Output.a <= 0.0f)
		discard;

	float2 pos = Input.Pos.xy / Input.Pos.w;
	float2 posU = Input.Tangent.xy / Input.Tangent.w;
	float2 posR = Input.Binormal.xy / Input.Binormal.w;

	float xscale = (Output.x * 2.0 - 1.0) * Input.Color.x * g_scale.x;
	float yscale = (Output.y * 2.0 - 1.0) * Input.Color.y * g_scale.x;

	float2 uv = pos + (posR - pos) * xscale + (posU - pos) * yscale;

	uv.x = (uv.x + 1.0) * 0.5;
	uv.y = 1.0 - (uv.y + 1.0) * 0.5;

	uv.y = mUVInversedBack.x + mUVInversedBack.y * uv.y;

	float3 color = tex2D(g_backSampler, uv);
	Output.xyz = color;

	return Output;
}
