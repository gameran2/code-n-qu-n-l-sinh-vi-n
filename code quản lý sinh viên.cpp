#include <iostream>
#include <fstream>
#include <string>

struct SinhVien {
    int id;
    std::string ten;
    std::string gioiTinh;
    float diemTB;
    SinhVien* next;
    SinhVien* prev;
};

struct  QuanLySinhVien {
private:
    SinhVien* head; // dau  
    SinhVien* tail; // cuoi  

public:
    QuanLySinhVien();
    ~QuanLySinhVien();

    void nhapDanhSachSinhVien();
    void themSinhVienDauDanhSach();
    void themSinhVienCuoiDanhSach();
    void themSinhVienViTriBatKy();
    void capNhapThongTinSinhVien(SinhVien* sv);
    void xoaSinhVienDauDanhSach();
    void xoaSinhVienCuoiDanhSach();
    void xoaSinhVienTheoID(int id);
    void capNhapID(int oldID, int newID);
    void xoaSinhVienTheoTen(std::string ten);
    void sapXepTheoDiemTB();
    float tinhDiemTrungBinh();
    void hienThiHocLucYeu();
    void hienThiSinhVienNam();
    void hienThiSinhVienNu();
    void xuatDanhSachSinhVien();
    void xuatFile(std::string filename);
    void xemDanhSachSinhVienGioi();
    void xemDanhSachSinhVienKha();
    void xemHocSinhXuatSac(int n);
    void hocSinhDuYeuCauLenLop();
    void danhSachHocSinhOLaiLop();
    void guiThongBaoChoPhuHuynh();
    void xemDiemDanh();
    void capNhatThongTinLienLac();
    void xoaTatCaSinhVien();
    void menu();
    
private:
    SinhVien* timSinhVienTheoID(int id);
};

QuanLySinhVien::QuanLySinhVien() {
    head = NULL;
    tail = NULL;
}

QuanLySinhVien::~QuanLySinhVien() {
    SinhVien* current = head;
    while (current != NULL) {
        SinhVien* next = current->next;
        delete current;
        current = next;
    }
    head = NULL;
    tail = NULL; // huy 
}

void QuanLySinhVien::nhapDanhSachSinhVien() {
    int n;
    std::cout << "so luong sinh  ";
    std::cin >> n;

    for (int i = 0; i < n; ++i) {
        SinhVien* sv = new SinhVien;
        std::cout << "nhap thong tin sinh vien " << i + 1 << ":" << std::endl;
        std::cout << "ID: ";
        std::cin >> sv->id;
        std::cout << "ten: ";
        std::cin.ignore(); // don dep bo nho 
        std::getline(std::cin, sv->ten);
        std::cout << "Gioi tinh: ";
        std::getline(std::cin, sv->gioiTinh);
        std::cout << "diem trung binh: ";
        std::cin >> sv->diemTB;

        sv->next = NULL;
        sv->prev = NULL;

        if (head == NULL) {
            head = sv;
            tail = sv;
        } else {
            tail->next = sv;
            sv->prev = tail;
            tail = sv;
        }
    }
}

void QuanLySinhVien::themSinhVienDauDanhSach() {
    SinhVien* sv = new SinhVien;
    std::cout << "nhap thong tin sinh vien:" << std::endl;
    std::cout << "ID: ";
    std::cin >> sv->id;
    std::cout << "T?n: ";
    std::cin.ignore();
    std::getline(std::cin, sv->ten);
    std::cout << "gioi tinh: ";
    std::getline(std::cin, sv->gioiTinh);
    std::cout << "diem trung binh: ";
    std::cin >> sv->diemTB;

    sv->next = head;
    sv->prev = NULL;

    if (head != NULL) {
        head->prev = sv;
    }
    head = sv;

    if (tail == NULL) {
        tail = sv;
    }
}

void QuanLySinhVien::themSinhVienCuoiDanhSach() {
    SinhVien* sv = new SinhVien;
    std::cout << "nhap thong tin vao cuoi danh sach:" << std::endl;
    std::cout << "ID: ";
    std::cin >> sv->id;
    std::cout << "T?n: ";
    std::cin.ignore();
    std::getline(std::cin, sv->ten);
    std::cout << "Gioi tinh: ";
    std::getline(std::cin, sv->gioiTinh);
    std::cout << "?iem trung binh: ";
    std::cin >> sv->diemTB;

    sv->next = NULL;
    sv->prev = tail;

    if (tail != NULL) {
        tail->next = sv;
    } 
    tail = sv;

    if (head == NULL) {
        head = sv;
    }
}

void QuanLySinhVien::themSinhVienViTriBatKy() {
    int pos;
    std::cout << "nhap vi tri chen sinh vien ";
    std::cin >> pos;

    if (pos < 0) {
        std::cout << "Vi tri khong hop le." << std::endl;
        return;
    }

    SinhVien* sv = new SinhVien;
    std::cout << "nhap thong tin sinh vien moi:" << std::endl;
    std::cout << "ID: ";
    std::cin >> sv->id;
    std::cout << "T?n: ";
    std::cin.ignore();
    std::getline(std::cin, sv->ten);
    std::cout << "gioi tinh: ";
    std::getline(std::cin, sv->gioiTinh);
    std::cout << "diem trung binh: ";
    std::cin >> sv->diemTB;

    sv->next = NULL;
    sv->prev = NULL;

    if (pos == 0) {
        sv->next = head;
        if (head != NULL) {
            head->prev = sv;
        }
        head = sv;
        if (tail == NULL) {
            tail = sv;
        }
        return;
    }

    SinhVien* current = head;
    int count = 0;

    while (current != NULL && count < pos - 1) {
        current = current->next;
        count++;
    }

    if (current == NULL) {
        std::cout << "vi tri chen khong hop le." << std::endl;
        delete sv;
        return;
    }

    sv->next = current->next;
    sv->prev = current;
    if (current->next != NULL) {
        current->next->prev = sv;
    }
    current->next = sv;

    if (sv->next == NULL) {
        tail = sv;
    }
}

void QuanLySinhVien::capNhapThongTinSinhVien(SinhVien* sv) {
    std::cout << "nhap tt sinh vi?n c? ID " << sv->id << ":" << std::endl;
    std::cout << "T?n: ";
    std::cin.ignore();
    std::getline(std::cin, sv->ten);
    std::cout << "Gioi tinh: ";
    std::getline(std::cin, sv->gioiTinh);
    std::cout << "?iem trung binh: ";
    std::cin >> sv->diemTB;
}

void QuanLySinhVien::xoaSinhVienDauDanhSach() {
    if (head == NULL) {
        std::cout << "Danh sacch sinh vien rong." << std::endl;
        return;
    }

    SinhVien* svToDelete = head;
    head = head->next;

    if (head != NULL) {
        head->prev = NULL;
    } else {
        tail = NULL;
    }

    delete svToDelete;
}

void QuanLySinhVien::xoaSinhVienCuoiDanhSach() {
    if (tail == NULL) {
        std::cout << "Danh sacch sinh vien rong." << std::endl;
        return;
    }

    SinhVien* svToDelete = tail;
    tail = tail->prev;

    if (tail != NULL) {
        tail->next = NULL;
    } else {
        head = NULL;
    }

    delete svToDelete; 
}

void QuanLySinhVien::xoaSinhVienTheoID(int id) {
    SinhVien* svToDelete = timSinhVienTheoID(id);

    if (svToDelete == NULL) {
        std::cout << "khong tim thay sinh vien  " << id << "." << std::endl;
        return;
    }

    if (svToDelete == head) {
        head = svToDelete->next;
    } else {
        svToDelete->prev->next = svToDelete->next;
    }

    if (svToDelete == tail) {
        tail = svToDelete->prev;
    } else {
        svToDelete->next->prev = svToDelete->prev;
    }

    delete svToDelete;
}

void QuanLySinhVien::capNhapID(int oldID, int newID) {
    SinhVien* sv = timSinhVienTheoID(oldID);

    if (sv == NULL) {
        std::cout << "khong tim thay" << oldID << "." << std::endl;
        return;
    }

    sv->id = newID;
}

void QuanLySinhVien::xoaSinhVienTheoTen(std::string ten) {
    SinhVien* current = head;

    while (current != NULL) {
        if (current->ten == ten) {
            if (current == head) {
                head = current->next;
            } else {
                current->prev->next = current->next;
            }

            if (current == tail) {
                tail = current->prev;
            } else {
                current->next->prev = current->prev;
            }

            SinhVien* svToDelete = current;
            current = current->next;
            delete svToDelete;
        } else {
            current = current->next;
        }
    }
}

void QuanLySinhVien::sapXepTheoDiemTB() {
    if (head == NULL || head == tail) {
        return;
    }

    bool swapped;
    SinhVien* ptr1;
    SinhVien* lptr = NULL;

    do {
        swapped = false;
        ptr1 = head;

        while (ptr1->next != lptr) {
            if (ptr1->diemTB < ptr1->next->diemTB) {
                std::swap(ptr1->id, ptr1->next->id);
                std::swap(ptr1->ten, ptr1->next->ten);
                std::swap(ptr1->gioiTinh, ptr1->next->gioiTinh);
                std::swap(ptr1->diemTB, ptr1->next->diemTB);
                swapped = true;
            }
            ptr1 = ptr1->next;
        }
        lptr = ptr1;
    } while (swapped);
}

float QuanLySinhVien::tinhDiemTrungBinh() {
    float sum = 0.0;
    int count = 0;
    SinhVien* current = head;

    while (current != NULL) {
        sum += current->diemTB;
        count++;
        current = current->next;
    }

    return (count > 0) ? (sum / count) : 0.0;
}

void QuanLySinhVien::hienThiHocLucYeu() {
    SinhVien* current = head;

    while (current != NULL) {
        if (current->diemTB < 5.0) {
            std::cout << "Sinh vien " << current->ten << " co diem turng binh " << current->diemTB << " - hoc luc yeu." << std::endl;
        }
        current = current->next;
    }
}

void QuanLySinhVien::hienThiSinhVienNam() {
    SinhVien* current = head;

    while (current != NULL) {
        if (current->gioiTinh == "Nam") {
            std::cout << "Sinh vien " << current->ten << " - Gioi tinh Nam." << std::endl;
        }
        current = current->next;
    }
}

void QuanLySinhVien::hienThiSinhVienNu() {
    SinhVien* current = head;

    while (current != NULL) {
        if (current->gioiTinh == "Nu") {
            std::cout << "Sinh vien " << current->ten << " - Gioi tinh Nu." << std::endl;
        }
        current = current->next;
    }
}

void QuanLySinhVien::xuatDanhSachSinhVien() {
    SinhVien* current = head;

    while (current != NULL) {
        std::cout << "ID: " << current->id << ", T?n: " << current->ten << ", Gioi tinh: " << current->gioiTinh << ", diem trung binh: " << current->diemTB << std::endl;
        current = current->next;
    }
}

void QuanLySinhVien::xuatFile(std::string filename) {
    std::ofstream outFile(filename.c_str());

    if (!outFile.is_open()) {
        std::cerr << "Khong the mo file " << filename << " ?? ghi." << std::endl;
        return;
    }

    SinhVien* current = head;
    while (current != NULL) {
        outFile << current->id << "," << current->ten << "," << current->gioiTinh << "," << current->diemTB << std::endl;
        current = current->next;
    }

    outFile.close();
    std::cout << "Xuat danh sach sinh vien ra file " << filename << " thanh cong." << std::endl;
}

void QuanLySinhVien::xemDanhSachSinhVienGioi() {
    SinhVien* current = head;

    while (current != NULL) {
        if (current->diemTB >= 8.0) {
            std::cout << "Sinh vien " << current->ten << " - diem trung binh: " << current->diemTB << " - Hoc sinh gioi." << std::endl;
        }
        current = current->next;
    }
}

void QuanLySinhVien::xemDanhSachSinhVienKha() {
    SinhVien* current = head;

    while (current != NULL) {
        if (current->diemTB >= 6.5 && current->diemTB < 8.0) {
                std::cout << "Sinh vien " << current->ten << " - diem trung binh: " << current->diemTB << " - Hoc sinh kha." << std::endl;
        }
        current = current->next;
    }
}

void QuanLySinhVien::xemHocSinhXuatSac(int n) {
    SinhVien* current = head;
    int count = 0;

    while (current != NULL && count < n) {
        if (current->diemTB >= 9.0) {
               std::cout << "Sinh vien " << current->ten << " - diem trung binh: " << current->diemTB << " - Hoc sinh xuat sac." << std::endl;
            count++;
        }
        current = current->next;
    }

    if (count < n) {
        std::cout << "Khong co  " << n << " xaut sac." << std::endl;
    }
}

void QuanLySinhVien::hocSinhDuYeuCauLenLop() {
    SinhVien* current = head;

    while (current != NULL) {
        if (current->diemTB >= 8.0 && current->gioiTinh == "Nam") {
            std::cout << "Sinh vien " << current->ten << " dieu  kien len lop." << std::endl;
        }
        current = current->next;
    }
}

void QuanLySinhVien::danhSachHocSinhOLaiLop() {
    SinhVien* current = head;

    while (current != NULL) {
        if (current->diemTB < 5.0) {
            std::cout << "Sinh vien " << current->ten << " dieu  kien len lop." << std::endl;
        }
        current = current->next;
    }
}

void QuanLySinhVien::guiThongBaoChoPhuHuynh() {
    SinhVien* current = head;

    while (current != NULL) {
        if (current->diemTB < 5.0) {
            std::cout << "Gui thong bao cho phu huynh cua sinh vien " << current->ten << " vi tinh trang hoc tap." << std::endl;
        }
        current = current->next;
    }
}

void QuanLySinhVien::xemDiemDanh() {
    SinhVien* current = head;

    while (current != NULL) {
        std::cout << "Sinh vien " << current->ten << " - ID: " << current->id << " - diem danh." << std::endl;
        current = current->next;
    }
}

void QuanLySinhVien::capNhatThongTinLienLac() {
    SinhVien* current = head;

    while (current != NULL) {
        std::cout << "Cap nhat th?ng tin lien lac cho sinh vien " << current->ten << " - ID: " << current->id << std::endl;

        current = current->next;
    }
}

void QuanLySinhVien::xoaTatCaSinhVien() {
    SinhVien* current = head;
    SinhVien* next = NULL;

    while (current != NULL) {
        next = current->next;
        delete current;
        current = next;
    }

    head = NULL;
    tail = NULL;

    std::cout << "xoa toan bo sinh vien khoi danh sach." << std::endl;
}

void QuanLySinhVien::menu() {
    int choice;
    do {
        std::cout << "\n===== MENU =====\n";
        std::cout << "1. Nhap danh sach sinh vien\n";
        std::cout << "2. Them sinh vien vao dau danh sach\n";
        std::cout << "3. Them sinh vien vao cuoi danh sach\n";
        std::cout << "4. Them sinh vien vao vi tri bat ki\n";
        std::cout << "5. Cap nhat thong tin sinh vien\n";
        std::cout << "6. Xoa sinh vien  dau danh sach\n";
        std::cout << "7. Xoa sinh vien  cuoi danh sach\n";
        std::cout << "8. Xoa sinh vien theo ID\n";
        std::cout << "9. Cap nhat ID sinh vien\n";
        std::cout << "10. xoa sinh vien theo ten\n";
        std::cout << "11. Sap xep sinh vien theo diem trung binh giam dan\n";
        std::cout << "12. Tinh diem trung binh cua toan bo sinh vien\n";
        std::cout << "13. Hien thi danh sach sinh vien hoc luc yeu\n";
        std::cout << "14. Hien thi danh sach sinh vien nam\n";
        std::cout << "15. Hien thi danh sach sinh vien nu\n";
        std::cout << "16. Xuat danh sach sinh vien\n";
        std::cout << "17. Xuat danh sach sinh vien vao file\n";
        std::cout << "18. Xem danh sach sinh vien hoc sinh gioi\n";
        std::cout << "19. Xem danh sach sinh vien hoc sinh kha\n";
        std::cout << "20. Xem danh sach  sinh vien xuaut sac\n";
        std::cout << "21. Danh sach hoc sinh nam du dieu kien len lop\n";
        std::cout << "22. Danh sach hoc sinh khong dieu kien len lop\n";
        std::cout << "23. Gui thong bao cho phu huynh hoc sinh yeu\n";
        std::cout << "24. Xem diiem danh cua sinh vien\n";
        std::cout << "25. Cap nhat th?ng tin lien lac cua sinh vi?n\n";
        std::cout << "26. Xa toan bo sinh vien khoi danh s?ch\n";
        std::cout << "27. Thoat chuong  trinh\n";
        std::cout << "Chon chuc nang: ";
        std::cin >> choice;

        switch (choice) {
            case 1:
                nhapDanhSachSinhVien();
                break;
            case 2:
                themSinhVienDauDanhSach();
                break;
            case 3:
                themSinhVienCuoiDanhSach();
                break;
            case 4:
                themSinhVienViTriBatKy();
                break;
            case 5: {
                int id;
                std::cout << "nhap id can cap nhap: ";
                std::cin >> id;
                SinhVien* sv = timSinhVienTheoID(id);
                if (sv != NULL) {
                    capNhapThongTinSinhVien(sv);
                } else {
                    std::cout << "khong tim thay " << id << "." << std::endl;
                }
                break;
            }
            case 6:
                xoaSinhVienDauDanhSach();
                break;
            case 7:
                xoaSinhVienCuoiDanhSach();
                break;
            case 8: {
                int id;
                std::cout << "id can xoa: ";
                std::cin >> id;
                xoaSinhVienTheoID(id);
                break;
            }
            case 9: {
                int oldID, newID;
                std::cout << "nhap id sinh vien: ";
                std::cin >> oldID;
                std::cout << "id moi sinh vien: ";
                std::cin >> newID;
                capNhapID(oldID, newID);
                break;
            }
            case 10: {
                std::string ten;
                std::cout << "nhap ten can xoa: ";
                std::cin.ignore();
                std::getline(std::cin, ten);
                xoaSinhVienTheoTen(ten);
                break;
            }
            case 11:
                sapXepTheoDiemTB();
                std::cout << "sap xem theo diem tb." << std::endl;
                break;
            case 12:
                std::cout << "diem trung binh cua toan bo sinh vien la: " << tinhDiemTrungBinh() << std::endl;
                break;
            case 13:
                hienThiHocLucYeu();
                break;
            case 14:
                hienThiSinhVienNam();
                break;
            case 15:
                hienThiSinhVienNu();
                break;
            case 16:
                xuatDanhSachSinhVien();
                break;
            case 17: {
                std::string filename;
                std::cout << "Nhap ten file  ";
                std::cin >> filename;
                xuatFile(filename);
                break;
            }
            case 18:
                xemDanhSachSinhVienGioi();
                break;
            case 19:
                xemDanhSachSinhVienKha();
                break;
            case 20: {
                int n;
                std::cout << "Nhap so luong sinh vien xuat sac can xem: ";
                std::cin >> n;
                xemHocSinhXuatSac(n);
                break;
            }
            case 21:
                hocSinhDuYeuCauLenLop();
                break;
            case 22:
                danhSachHocSinhOLaiLop();
                break;
            case 23:
                guiThongBaoChoPhuHuynh();
                break;
            case 24:
                xemDiemDanh();
                break;
            case 25:
                capNhatThongTinLienLac();
                break;
            case 26:
                xoaTatCaSinhVien();
                break;
            case 27:
                std::cout << "thoat chuong trinh";
                break;
            default:
                std::cout << "khong hop le.\n";
                break;
        }
    } while (choice != 27);
}

SinhVien* QuanLySinhVien::timSinhVienTheoID(int id) {
    SinhVien* current = head;

    while (current != NULL) {
        if (current->id == id) {
            return current;
        }
        current = current->next;
    }

    return NULL;
}

int main() {
    QuanLySinhVien qlsv;
    qlsv.menu();

    return 0;
}

