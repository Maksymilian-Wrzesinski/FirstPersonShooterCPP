.PHONY: clean All

All:
	@echo "----------Building project:[ FirstPersonShooter - Debug ]----------"
	@cd "FirstPersonShooter" && "$(MAKE)" -f  "FirstPersonShooter.mk"
clean:
	@echo "----------Cleaning project:[ FirstPersonShooter - Debug ]----------"
	@cd "FirstPersonShooter" && "$(MAKE)" -f  "FirstPersonShooter.mk" clean
