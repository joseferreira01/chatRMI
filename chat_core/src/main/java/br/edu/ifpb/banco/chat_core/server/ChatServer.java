/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package br.edu.ifpb.banco.chat_core.server;

import br.edu.ifpb.banco.chat_core.conexao.Conexao;
import br.edu.ifpb.pod.chat.shared.Mensagem;
import java.sql.Connection;
import java.sql.PreparedStatement;
import java.sql.SQLException;
import java.util.logging.Level;
import java.util.logging.Logger;
import javax.websocket.Session;


/**
 *
 * @author jose
 */
public class ChatServer implements br.edu.ifpb.pod.chat.shared.ChatServer{
private Conexao conexao;
    @Override
    public Session login(String email) {
          Connection conn = conexao.init();
          try {
            String sql = "delete userConection WHERE email=?";
            
            PreparedStatement statement = conn.prepareStatement(sql);
            statement.setString(1, email);
            statement.executeUpdate();
            insert(conn,email);
        } catch (SQLException ex) {
            Logger.getLogger(Mensagem.class.getName()).log(Level.SEVERE, null, ex);
        }
         finally{
            try {
                Conexao.fecharConexao(conn);
            } catch (SQLException ex) {
                Logger.getLogger(Mensagem.class.getName()).log(Level.SEVERE, null, ex);
            }
        }
    return null;
    
    }

    @Override
    public void persisteAndforward(Mensagem message) {
        throw new UnsupportedOperationException("Not supported yet."); //To change body of generated methods, choose Tools | Templates.
    }

    @Override
    public void remove(Mensagem msg) {
          Connection conn = conexao.init();
          try {
            String sql = "UPDATE mensagem SET is_remove=true WHERE id=?";
            
            PreparedStatement statement = conn.prepareStatement(sql);
            statement.setLong(1, msg.getID());
            statement.executeUpdate();
        } catch (SQLException ex) {
            Logger.getLogger(Mensagem.class.getName()).log(Level.SEVERE, null, ex);
        }
         finally{
            try {
                Conexao.fecharConexao(conn);
            } catch (SQLException ex) {
                Logger.getLogger(Mensagem.class.getName()).log(Level.SEVERE, null, ex);
            }
        }
    }

    private void insert(Connection conn,String email) {
          
          try {
            String sql = "inset into  userConection (email,is_remove) values(?,?) WHERE email=?";
            
            PreparedStatement statement = conn.prepareStatement(sql);
            statement.setString(1, email);
             statement.setBoolean(2, true);
            statement.executeUpdate();
        } catch (SQLException ex) {
            Logger.getLogger(Mensagem.class.getName()).log(Level.SEVERE, null, ex);
        }
         finally{
            try {
                Conexao.fecharConexao(conn);
            } catch (SQLException ex) {
                Logger.getLogger(Mensagem.class.getName()).log(Level.SEVERE, null, ex);
            }
        }
    return;
    
    }
    
}
