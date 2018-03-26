#include "Shader.h"

void

// Constructeurs et Destructeur

t_shader	*new shader(char *vertex_source, char *fragment_source)
{
	t_shader *res;

	res = malloc(sizeof(t_shader));
	res->m_vertex_id = 0;
	res->m_fragment_id = 0;
	res->m_program_id = 0;
	res->m_vertex_source = ft_strdup(vertex_source);
	res->m_fragment_source = ft_strdup(fragment_source);
	return (res);
}
						
// Shader::Shader(Shader const &shaderACopier)
// {
//     // Copie des fichiers sources

//     m_vertexSource = shaderACopier.m_vertexSource;
//     m_fragmentSource = shaderACopier.m_fragmentSource;


//     // Chargement du nouveau shader

//     charger();
// }


// Shader::Shader(std::string vertexSource, std::string fragmentSource) : m_vertexID(0), m_fragmentID(0), m_programID(0),
//                                                                        m_vertexSource(vertexSource), m_fragmentSource(fragmentSource)
// {
// }


// Shader::~Shader()
// {
//     // Destruction du shader

//     glDeleteShader(m_vertexID);
//     glDeleteShader(m_fragmentID);
//     glDeleteProgram(m_programID);
// }


// M�thodes


// Shader& Shader::operator=(Shader const &shaderACopier)
// {
//     // Copie des fichiers sources

//     m_vertexSource = shaderACopier.m_vertexSource;
//     m_fragmentSource = shaderACopier.m_fragmentSource;


//     // Chargement du nouveau shader

//     charger();


//     // Retour du pointeur this

//     return *this;
// }


int shd_charge(t_shader *shader)
{
	// Destruction d'un �ventuel ancien Shader

	if (glIsShader(shader->m_vertex_id) == GL_TRUE)
		glDeleteShader(shader->m_vertex_id);
	if (glIsShader(shader->m_fragment_id) == GL_TRUE)
		glDeleteShader(shader->m_fragment_id);
	if (glIsProgram(shader->m_program_id) == GL_TRUE)
		glDeleteProgram(shader->m_program_id);

	// Compilation des shaders
	if (!compilerShader(&(shader->m_vertex_id), GL_VERTEX_SHADER, shader->m_vertex_source))
		return 0;
	if (!compilerShader(&(shader->m_fragment_id), GL_FRAGMENT_SHADER, shader->m_fragment_source))
		return 0;

	// Cr�ation du programme

	shader->m_program_id = glCreateProgram();


	// Association des shaders

	glAttachShader(shader->m_program_id, shader->m_vertex_id);
	glAttachShader(shader->m_program_id, shader->m_fragment_id);

	// Verrouillage des entr�es shader

	glBindAttribLocation(shader->m_program_id, 0, "in_Vertex");
	glBindAttribLocation(shader->m_program_id, 1, "in_Color");
	glBindAttribLocation(shader->m_program_id, 2, "in_TexCoord0");


	// Linkage du programme

	glLinkProgram(shader->m_program_id);


	// V�rification du linkage

	GLint erreurLink = 0;
	glGetProgramiv(shader->m_program_id, GL_LINK_STATUS, &erreurLink);


	// S'il y a eu une erreur

	if(erreurLink != GL_TRUE)
	{
		// R�cup�ration de la taille de l'erreur

		GLint tailleErreur = 0;
		glGetProgramiv(shader->m_program_id, GL_INFO_LOG_LENGTH, &tailleErreur);


		// Allocation de m�moire

		char *erreur = new char[tailleErreur + 1];
		// R�cup�ration de l'erreur

		glGetShaderInfoLog(shader->m_program_id, tailleErreur, &tailleErreur, erreur);
		erreur[tailleErreur] = '\0';
		// Affichage de l'erreur
		// std::cout << erreur << std::endl;

		// Lib�ration de la m�moire et retour du bool�en false
		free(erreur);
		glDeleteProgram(shader->m_program_id);
		return false;
	}

	// Sinon c'est que tout s'est bien pass�

	else
		return true;
}

int     shd_compile(int *shader_id, GLenum type, char *filename)
{
	int fd;
	// Cr�ation du shader

	*shader_id = glCreateShader(type);

	// V�rification du shader

	if(*shader_id == 0)
		return 0;


	// Flux de lecture
	fd = open(filename, O_RDONLY);

	if (fd == -1)
	{
		glDeleteShader(*shader_id);
		return 0;
	}
	// Strings permettant de lire le code source
	char *line;
	char *source_code;

	source_code = ft_strnew(0);
	// Lecture
	while(get_next_line(fd, &line))
	{
		source_code = ft_strjoin(source_code, line);
	}
	// Fermeture du fichier

	close(fd);
	// R�cup�ration de la chaine C du code source

	const GLchar* chaineCodeSource = source_code;
	// Envoi du code source au shader

	glShaderSource(*shader_id, 1, &chaineCodeSource, 0);

	// Compilation du shader

	glCompileShader(*shader_id);


	// V�rification de la compilation

	GLint erreurCompilation = 0;
	glGetShaderiv(*shader_id, GL_COMPILE_STATUS, &erreurCompilation);


	// S'il y a eu une erreur

	if(erreurCompilation != GL_TRUE)
	{
		// R�cup�ration de la taille de l'erreur

		GLint tailleErreur = 0;
		glGetShaderiv(*shader_id, GL_INFO_LOG_LENGTH, &tailleErreur);
		// Allocation de m�moire

		char *erreur = new char[tailleErreur + 1];


		// R�cup�ration de l'erreur

		glGetShaderInfoLog(*shader_id, tailleErreur, &tailleErreur, erreur);
		erreur[tailleErreur] = '\0';


		// Affichage de l'erreur

		// std::cout << erreur << std::endl;


		// Lib�ration de la m�moire et retour du bool�en false

		free9(erreur);
		glDeleteShader(*shader_id);
		return 0;
	}
	// Sinon c'est que tout s'est bien pass�
	else
		return 1;
}


// Getter

// GLuint Shader::getProgramID() const
// {
// 	return m_programID;
// }
