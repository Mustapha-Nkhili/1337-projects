*This project has been created as a part of the 42 curriculum by mn-khili.*

# Born2beroot: Secure System Administration Setup

## Description

The **Born2beroot** project is a foundational system administration exercise focused on virtualization, and operating system installation (via CLI only).

### Main Design Choices

The following core decisions were made to ensure a stable and resilient environment:

* **Operating System:** I selected **Debian** for its high stability and extensive package ecosystem, which is ideal for a secure, long-term server setup.
* **Partitioning (LVM):** I implemented **Logical Volume Management (LVM)** with an encrypted layer. This allows for dynamic resizing of filesystems. Separate volumes were created for `/`, `/home`, `/var`, `/var/log`, `/srv`, and `/swap` to ensure that data growth in one area (like logs or web assets) does not crash the entire operating system.
* **Security Policies:** I enforced a strict password policy using `pam_pwquality`, requiring a minimum of 10 characters, upper and lowercase. **SSH** was hardened by disabling root login and moving the service to port **4242**.
* **User Management:** To adhere to the **Principle of Least Privilege**, administrative tasks are performed by a non-root user via `sudo`, with all privileged actions strictly logged to `/var/log/sudo/`.
* **Services Installed (bonus):** The server hosts a **WordPress** site using a lightweight stack (**lighttpd**, **MariaDB**, and **PHP-FPM**). Additionally, **Fail2ban** was implemented as a extra service to proactively block brute-force attempts.

---

### Technical Comparisons

#### ◦ Debian vs. Rocky Linux
| Feature | Debian (Selected) | Rocky Linux |
| :--- | :--- | :--- |
| **Pros** | Extremely lightweight, "Universal" support, and vast community. | Enterprise-grade, 100% RHEL binary compatibility. |
| **Cons** | Stable branch packages can be older. | Steep learning curve; heavier default configuration. |
| **Decision** | **Debian** was chosen for its reliability and the APT package manager's ease of use in a learning environment. | |

#### ◦ AppArmor vs. SELinux
| Feature | AppArmor (Selected) | SELinux |
| :--- | :--- | :--- |
| **Mechanism** | Path-based access control (identifies files by location). | Label-based control (identifies objects by security context). |
| **Complexity** | Simple, human-readable profiles; easy to debug. | Highly granular but extremely complex to manage. |
| **Decision** | **AppArmor** was chosen as it provides robust security without the administrative overhead of SELinux. | |



#### UFW vs. firewalld
| Feature | UFW (Selected) | firewalld |
| :--- | :--- | :--- |
| **Interface** | CLI focused on simplicity and speed. | Zone-based management for dynamic environments. |
| **Usage** | Ideal for standalone servers. | Better for machines moving between different networks. |
| **Decision** | **UFW** was chosen because its straightforward syntax (`ufw allow 4242`) minimizes the risk of configuration errors. | |

#### ◦ VirtualBox vs. UTM
| Feature | VirtualBox (Selected)  | UTM |
| :--- | :--- | :--- |
| **Architecture** | Optimized for x86 (Intel/AMD) machines. | Optimized for Apple Silicon (ARM M-series chips). |
| **Performance** | Industry standard for classic PC hardware. | Uses Apple's Virtualization Framework for native speed. |
| **Decision** | VirtualBox was selected because the school's Dell PCs run on x86_64 architecture. | |

---

# Instructions

### Prerequisites

* A virtualization software: **[VirtualBox or UTM]**.
* The Debian stable minimal installation ISO file.
* A host machine with an SSH client.

### Installation and Configuration

1.  **VM Creation:** Create a new VM with sufficient resources (e.g., 1GB RAM, 1 CPU Core, 30.8GB HDD) and select the Debian ISO.
2.  **CLI Installation:** Perform the **full installation via the command line (CLI)**, ensuring no graphical interface is installed.
3.  **LVM & Encryption:** Configure the disk using **Encrypted LVM** during the guided installation process, creating the required logical volumes.
4.  **Harden SSH:** Edit `/etc/ssh/sshd_config` to set `Port 4242`, `PermitRootLogin no`, and restart the service.
5.  **Configure UFW:**
    ```bash
    sudo apt install ufw
    sudo ufw allow 4242
    sudo ufw enable
    ```
6.  **Install Fail2Ban (Bonus Service):**
    ```bash
    sudo apt install fail2ban
    sudo cp /etc/fail2ban/jail.conf /etc/fail2ban/jail.local
    # Configure jail.local to protect sshd on port 4242
    ```
    *Fail2Ban* is a crucial service that monitors logs (e.g., `/var/log/auth.log` for SSH) and automatically updates the firewall (UFW) rules to ban offending IP addresses after a specified number of failed login attempts (`maxretry`).

---

## Resources

### References

* [Debian Official Documentation](https://www.debian.org/doc/)
* [UFW (Uncomplicated Firewall) Documentation](https://help.ubuntu.com/community/UFW)
* [Linux Logical Volume Manager (LVM) Guide](https://wiki.debian.org/LVM)
* [Learning The Linux File System 2025](https://www.youtube.com/watch?v=p9lCbFq8IPo)
* [Introduction to Linux – Full Course for Beginners](https://www.youtube.com/watch?v=sWbUDq4S6Y8)
* [Linux Crash Course - Connecting to Linux Servers via SSH](https://www.youtube.com/watch?v=kjFz7Lp8Qjk)
* [OpenSSH for Absolute Beginners](https://www.youtube.com/watch?v=3FKsdbjzBcc)

### AI Usage

Artificial Intelligence (Google Gemini) was used for:

* **Documentation Formatting:** Structuring the Markdown and comparison tables.
* **Command Verification:** Double-checking the syntax for `pam_pwquality` parameters and `lighttpd` module activation.
* **Conceptual Research:** Comparing the architectural differences between `/srv` and `/var/www`.

