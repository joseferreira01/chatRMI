/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package br.edu.ifpb.pod.chat.shared;

import javax.websocket.Session;

/**
 *
 * @author jose
 */
//entega msg
/**
 * --- usuarios
 * user(
 * varchar(100) email
 * )
 * userConection(
 * email varchar(100)
 * is_remove boolean
 * )
 * {adicionar }
 * caso usuario ja conectado, remova a conxao
 * @author jose
 */
public interface ChatServer {

    Session login(String email);
/**
 * database menssagen(
 * id long;
 * fron varchar(100)
 * msg varchar(256)
 * is_rmove bolean
 * )
 * percorre todos user existentes , e aprti da menssan criar umas lista de mensage_use as 
 * mensagen +usuari(por tupla)
 * mensagen_user(
 * id mesagen
 * email destinatario
 * is_sended  boolean
 * )
 * encaminhar msg 
 * @param message forward(Message message);

 */
    void persisteAndforward(Message message);

    void remove(Message msg);
}
