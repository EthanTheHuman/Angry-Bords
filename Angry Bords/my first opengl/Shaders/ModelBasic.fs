#version 450 core

in vec2 fragTexCoords;

out vec4 color;

uniform sampler2D texture_diffuse1;

void main(void)
{
	color = texture(texture_diffuse1, fragTexCoords);
}