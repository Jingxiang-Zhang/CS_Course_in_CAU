package webapp;

public class Loginbean {

    String[][] userList = {
        {"AAA", "aaa"}, {"BBB", "bbb"}, {"CCC", "ccc"}, {"DDD", "ddd"}
    };
    private String username;
    private String password;

    public String getUsername() {
        return username;
    }

    public void setUsername(String username) {
        this.username = username;
    }

    public String getPassword() {
        return password;
    }

    public void setPassword(String password) {
        this.password = password;
    }

    public String getCheck() {
        boolean flag = false;

        for (int i = 0; i < userList.length; i++) {
            if (userList[i][0].equals(username) == true && userList[i][1].equals(password) == true) {
                flag = true;
                break;
            }
        }
        if(flag==true){
            return "登录成功";
        }
        else{
            return "shibai";
        }
    }
}
