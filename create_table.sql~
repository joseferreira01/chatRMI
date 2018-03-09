CREATE TABLE usuario(
	email VARCHAR(100) PRIMARY KEY
 );
CREATE TABLE  mensagem(
	id serial PRIMARY KEY,
	fron varchar(100),
	is_remove boolean
);
 CREATE TABLE userConection(
  email varchar(100),
  FOREIGN KEY(email) REFERENCES Usuario(email),
  is_remove boolean
 );
 CREATE TABLE mensagem_user(
  id_mensagem int,
  email_destinatario varchar(100),
  is_sended  boolean,
  FOREIGN KEY(email_destinatario) REFERENCES Usuario(email),
  FOREIGN KEY(id_mensagem) REFERENCES mensagem(id)
 )
