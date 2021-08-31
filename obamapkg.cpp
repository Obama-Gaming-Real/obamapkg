#include <iostream>

using namespace std;
string package_command;
string package_to_install;
string user_shell;
string package_to_uninstall;

int main() {
  cout << "use the command help to get usage about obamapkg" << endl;
  cout << "obamapkg cmd > ";
    cin >> package_command;
      
    if(package_command == "install"){
        cout << "package > ";
        cin >> package_to_install;
          
        if(package_to_install == "firefox" ){
            cout << "" << endl;
            cout << "getting sources" << endl;
            system("wget https://download-installer.cdn.mozilla.net/pub/firefox/releases/91.0.2/linux-x86_64/en-US/firefox-91.0.2.tar.bz2");
            cout << "installing " << package_to_install << endl;
            system("tar xjf firefox-91.0.2.tar.bz2 && rm -rf firefox-91.0.2.tar.bz2 && mv firefox ~/.obamapkg/packages/");
            cout << "enter the root password to symlink " << package_to_install << " to path" << endl;
            system("sudo ln -s ~/.obamapkg/packages/firefox/firefox /usr/local/bin/firefox");
            system("sudo chmod +x /usr/local/bin/firefox");
            cout << "finished" << endl;
          }
        
        else if(package_to_install == "neofetch"){
          cout << "" << endl;
          cout << "getting sources" << endl;
          system("wget https://github.com/dylanaraps/neofetch/archive/refs/tags/7.1.0.tar.gz");
          cout << "installing " << package_to_install << endl;
          system("tar xvfz 7.1.0.tar.gz && rm -rf 7.1.0.tar.gz && mv neofetch-7.1.0 ~/.obamapkg/packages/neofetch");
          cout << "enter the root password to symlink " << package_to_install << " to path" << endl;
          system("sudo ln -s ~/.obamapkg/packages/neofetch/neofetch /usr/local/bin/neofetch");
          system("sudo chmod +x /usr/local/bin/neofetch");
          cout << "finished" << endl;
        }
    }

      else if(package_command == "uninstall"){
        cout << "package > ";
        cin >> package_to_uninstall;
          if(package_to_uninstall == "firefox"){
            cout << "enter the root password to delete the symlink to " << package_to_uninstall << endl;
            system("sudo rm -rf /usr/local/bin/firefox");
            system("rm -rf ~/.obamapkg/packages/firefox");
            cout << "done removing " << package_to_uninstall << endl;
          }
          
          if(package_to_uninstall == "neofetch"){
            cout << "enter the root password to delete the symlink to " << package_to_uninstall << endl;
            system("sudo rm -rf /usr/local/bin/neofetch");
            system("rm -rf ~/.obamapkg/packages/neofetch");
            cout << "done removing " << package_to_uninstall << endl;
          }
      }
 }
