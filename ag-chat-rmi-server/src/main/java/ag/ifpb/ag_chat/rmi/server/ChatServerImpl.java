package ag.ifpb.ag_chat.rmi.server;

import java.sql.Connection;
import java.sql.PreparedStatement;
import java.sql.ResultSet;
import java.sql.SQLException;
import java.util.ArrayList;
import java.util.List;
import java.util.logging.Level;
import java.util.logging.Logger;

import ag.ifpb.chat.rmi.share.ChatServer;
import ag.ifpb.chat.rmi.share.Message;
import ag.ifpb.chat.rmi.share.Session;

public class ChatServerImpl implements ChatServer {

	private void deleteUser(Connection conn, String email) throws SQLException {
		String sql = "update users_connected set is_removed=true WHERE uemail=?";
		PreparedStatement statement = conn.prepareStatement(sql);
		statement.setString(1, email);
		statement.executeUpdate();
	}

	private void insertUser(Connection conn, String token, String email) throws SQLException {
		String sql = "insert into users_connected (token, uemail, is_removed) values(?, ?,false)";
		PreparedStatement statement = conn.prepareStatement(sql);
		statement.setString(1, token);
		statement.setString(2, email);
		statement.executeUpdate();
	}
	
	private List<String> listAllUsers(Connection conn) throws SQLException{
		String sql = "select uemail,is_removed from users_connected WHERE is_removed=false";
		PreparedStatement statement = conn.prepareStatement(sql);
		ResultSet rs = statement.executeQuery();
		//
		List<String> result = new ArrayList<String>();
		while(rs.next()){
			result.add(rs.getString("uemail"));
		}
		//
		return result;
	}

	public Session login(String email) {
		Connection conn = Connector.init();
		Session session = null;
		try {
			//
			String token = String.valueOf(System.currentTimeMillis());
			//
			deleteUser(conn, email);
			insertUser(conn, token, email);
			//
			session = new Session();
			session.setToken(token);
			session.setUser(email);
			insertSession(session,conn);
		} catch (SQLException ex) {
			Logger.getLogger(ChatServerImpl.class.getName()).log(Level.SEVERE, null, ex);
		} finally {
			try {
				Connector.close();
			} catch (SQLException ex) {
				Logger.getLogger(ChatServerImpl.class.getName()).log(Level.SEVERE, null, ex);
			}
		}
		return session;
	}

	public void persistAndforwardToAll(Message msg) {
		String sql = "INSERT INTO messages_users(message_id, "
				+ "ufrom, uto, is_sended) VALUES (?, ?, ?, false);";
		//
		Connection conn = Connector.init();
		try {
			List<String> users = listAllUsers(conn);
			PreparedStatement ps = conn.prepareStatement(sql);
			//
			for (String uto : users) {
				ps.setLong(1, msg.getID());
				ps.setString(2, msg.getUser());
				ps.setString(3, uto);//
				ps.executeUpdate();
			}
		} catch (SQLException ex) {
			Logger.getLogger(ChatServerImpl.class.getName()).log(Level.SEVERE, null, ex);
		} finally {
			try {
				Connector.close();
			} catch (SQLException ex) {
				Logger.getLogger(ChatServerImpl.class.getName()).log(Level.SEVERE, null, ex);
			}
		}
	}

	public void remove(Message msg) {
		Connection conn = Connector.init();
		try {
			String sql = "UPDATE messages SET is_removed = true WHERE id = ?;";
			//
			PreparedStatement statement = conn.prepareStatement(sql);
			statement.setLong(1, msg.getID());
			statement.executeUpdate();
			//
		} catch (SQLException ex) {
			Logger.getLogger(ChatServerImpl.class.getName()).log(Level.SEVERE, null, ex);
		} finally {
			try {
				Connector.close();
			} catch (SQLException ex) {
				Logger.getLogger(ChatServerImpl.class.getName()).log(Level.SEVERE, null, ex);
			}
		}

	}

    private void insertSession(Session session, Connection conn) {
        try {
			String sql = "INSERT INTO Session (TOKEN,userSession,LIVE) VALUES(?,?,?);";
			//
			PreparedStatement statement = conn.prepareStatement(sql);
			statement.setString(1, session.getToken());
			statement.setString(1, session.getUser());
			statement.setBoolean(1, true);
			statement.executeUpdate();
			//
		} catch (SQLException ex) {
			Logger.getLogger(ChatServerImpl.class.getName()).log(Level.SEVERE, null, ex);
		} //finally {
//			try {
//				Connector.close();
//			} catch (SQLException ex) {
//				Logger.getLogger(ChatServerImpl.class.getName()).log(Level.SEVERE, null, ex);
//			}
//		}

    }

}
